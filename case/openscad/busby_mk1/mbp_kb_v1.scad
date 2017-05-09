// -*- mode: c -*-
/* All distances are in mm. */

// include <TextGenerator_after_2015.03.scad>;
// include <dimlines.scad>;

/* set output quality */
$fn = 50;

/* Distance between key centers. */
column_spacing   = 19;
row_spacing      = column_spacing;

/* Dimensions of frame */
frame_width = 320;
frame_height = 150;

/* This number should exceed row_spacing and column_spacing. The
 default gives a 1mm = (20mm - 19mm) gap between keycaps and cuts in
 the top plate.*/
key_hole_size = 20;

/* rotation angle; the angle between the halves is twice this
   number */
angle = 8;

/* The radius of screw holes. Holes will be slightly bigger due
   to the cut width. */
screw_hole_radius = 1.5;
/* Each screw hole is a hole in a "washer". How big these "washers"
   should be depends on the material used: this parameter and the
   `switch_hole_size` determine the spacer wall thickness. */
//washer_radius     = 4 * screw_hole_radius;
washer_radius = 5;

/* This constant allows tweaking the location of the screw holes near
   the USB cable. Only useful with small `angle` values. Try the value
   of 10 with angle=0. */
back_screw_hole_offset = 0;

/* Distance between halves. */
hand_separation        = 10;

/* The approximate size of switch holes. Used to determine how
   thick walls can be, i.e. how much room around each switch hole to
   leave. See spacer(). */
switch_hole_size = 10;

/* Sets whether the case should use notched holes. As far as I can
   tell these notches are not all that useful... */
use_notched_holes = true;

/* Number of rows and columns in the matrix. You need to update
   staggering_offsets if you change n_cols. */
n_rows = 4;
n_cols = 6;

/* Number of thumb keys (per hand), try 1 or 2. */
n_thumb_keys = 2;

/* The width of the USB cable hole in the spacer. */
cable_hole_width = 20;

/* Vertical column staggering offsets. The first element should
   be zero. */
   // staggering_offsets = [0, 5, 11, 6, 3, 3];
   staggering_offsets = [0, 4, 8, 2, -9, -16];

module rz(angle, center=undef) {
  /* Rotate children `angle` degrees around `center`. */
  translate(center) {
    rotate(angle) {
      translate(-center) {
        for (i=[0:$children-1])
          child(i);
      }
    }
  }
}

/* Compute coordinates of a point obtained by rotating p angle degrees
   around center. Used to compute locations of screw holes near the
   USB cable hole. */
function rz_fun(p, angle, center) = [cos(angle) * (p[0] - center[0]) - sin(angle) * (p[1] - center[1]) + center[0],
                                     sin(angle) * (p[0] - center[0]) + cos(angle) * (p[1] - center[1])+ center[1]];

module switch_hole(position, notches=use_notched_holes) {
  /* Cherry MX switch hole with the center at `position`. Sizes come
     from the ErgoDox design. */
  hole_size    = 13.97;
  notch_width  = 3.5001;
  notch_offset = 4.2545;
  notch_depth  = 0.8128;
  translate(position) {
    union() {
      square([hole_size, hole_size], center=true);
      if (notches == true) {
        translate([0, notch_offset]) {
          square([hole_size+2*notch_depth, notch_width], center=true);
        }
        translate([0, -notch_offset]) {
          square([hole_size+2*notch_depth, notch_width], center=true);
        }
      }
    }
  }
};

module regular_key(position, size) {
  /* Create a hole for a regular key. */
  translate(position) {
    square([size, size], center=true);
  }
}

module thumb_key(position, size) {
  /* Create a hole for a 1x2 unit thumb key. */
  translate(position) {
    scale([1, 2]) {
      translate(-position) {
        regular_key(position, size);
      }
    }
  }
}

module column (bottom_position, switch_holes, key_size=key_hole_size, rows) {
  /* Create a column of keys. */
  translate(bottom_position) {
    for (i = [0:(rows-1)]) {
      if (switch_holes == true) {
        switch_hole([0, i*column_spacing]);
      } else {
        regular_key([0, i*column_spacing], key_size);
      }
    }
  }
}

module rotate_half() {
  /* Rotate the right half of the keys around the top left corner of
     the thumb key. Assumes that the thumb key is a 1x1.5 key and that
     it is shifted 0.5*column_spacing up relative to the nearest column. */
  rotation_y_offset = 1.75 * column_spacing;
  for (i=[0:$children-1]) {
    rz(angle, [hand_separation, rotation_y_offset]) {
      child(i);
    }
  }
}

module add_hand_separation() {
  /* Shift everything right to get desired hand separation. */
  for (i=[0:$children-1]) {
    translate([0.5*hand_separation, /* we get back the full separation
                                       because of mirroring */
               0]) child(i);
  }
}

module right_half (switch_holes=true, key_size=key_hole_size) {
  /* Create switch holes or key holes for the right half of the
     keyboard. Different key_sizes are used in top_plate() and
     spacer(). */
  x_offset = 0.5 * row_spacing;
  y_offset = (0.5 * column_spacing) + column_spacing;
  thumb_key_offset = (y_offset + 0.5 * column_spacing) - column_spacing;
  //   thumb_key_offset = (y_offset) - column_spacing;
  rotate_half() {
    add_hand_separation() {
        if (switch_holes == true) {
          switch_hole([x_offset + row_spacing, thumb_key_offset]);
          switch_hole([x_offset, (y_offset)]);
          switch_hole([x_offset, (y_offset - column_spacing)]);
        } else {
            thumb_key([x_offset + 1*row_spacing, thumb_key_offset], key_size);
            regular_key([x_offset, (thumb_key_offset - (0.5 * column_spacing))], key_size);
            regular_key([x_offset, thumb_key_offset + 0.5 + (0.5 * column_spacing)], key_size);
        }      
      for (j=[0:(n_cols-1)]) {
          orig = n_rows;
          if(j<3) {
              column([x_offset + (j+n_thumb_keys)*row_spacing, y_offset + staggering_offsets[j]], switch_holes, key_size, n_rows);
          }else{
              column([x_offset + (j+n_thumb_keys)*row_spacing, y_offset + staggering_offsets[j] + column_spacing], switch_holes, key_size, (n_rows-1));
          }
          
          n_rows = orig;
      }
    }
  }
}

module screw_hole(radius, offset_radius, position, direction) {
  /* Create a screw hole of radius `radius` at a location
     `offset_radius` from `position`, (diagonally), in the direction
     `direction`. Oh, what a mess this is. */
  /* direction is the 2-element vector specifying to which side of
     position to move to, [-1, -1] for bottom left, etc. */

  /* radius_offset is the offset in the x (or y) direction so that
     we're offset_radius from position */
  radius_offset = offset_radius; // / sqrt(2);
  /* key_hole_offset if the difference between key spacing and key
     hole edge */
  // key_hole_offset = 0.5*(row_spacing - key_hole_size);
    key_hole_offset = 0;
  x = position[0] + (radius_offset - key_hole_offset) * direction[0];
  y = position[1] + (radius_offset - key_hole_offset) * direction[1];
  translate([x,y]) {
    circle(radius);
  }
}

module right_screw_holes(hole_radius) {
       screw_hole(hole_radius, washer_radius,
                 [(frame_width / 2), 0],
                 [-1, 1]);
       screw_hole(hole_radius, washer_radius,
                 [(frame_width / 2), frame_height],
                 [-1, -1]);
  } 

module screw_holes(hole_radius) {
  /* Create all the screw holes. */
  right_screw_holes(hole_radius);
  mirror ([1,0,0]) { right_screw_holes(hole_radius); }
}

module left_half(switch_holes=true, key_size=key_hole_size) {
  mirror ([1,0,0]) { right_half(switch_holes, key_size); }
}

module bottom_plate() {
  /* bottom layer of the case */
  difference() {
    hull() { screw_holes(washer_radius); }
    screw_holes(screw_hole_radius);
  }
}

module logo(){
    logo_rad = 15;
    translate([15,95]) { circle( (logo_rad / 3.5) );}    
    translate([0,80]) { circle(logo_rad); }
    translate([0,57]) { scale([1,0.33]) { circle(logo_rad);} }
}

module top_plate() {
  /* top layer of the case */
  difference() {
    bottom_plate();
    right_half(false);
    left_half(false);
    logo();
  }
}

module switch_plate() {
  /* the switch plate */
  difference() {
    bottom_plate();
    right_half();
    left_half();
  }
}

module spacer() {
  /* Create a spacer. */
  difference() {
    union() {
      difference() {
        bottom_plate();
        hull() {
          right_half(switch_holes=false, key_size=switch_hole_size + 3);
          left_half(switch_holes=false, key_size=switch_hole_size + 3);
        }
    /* add the USB cable hole: */
    translate([-0.5*cable_hole_width, 2*column_spacing]) {
      square([cable_hole_width, (2*n_rows) * column_spacing]);
    }
      }
      screw_holes(washer_radius);
    }
    screw_holes(screw_hole_radius);
  }
}

/* Create all four layers. */
bottom_plate();
// top_plate();
// translate([355, 150]) { spacer(); }
// translate([355, 0]) { switch_plate(); }
// translate([0, 150]) { bottom_plate(); }
