bool IsPointInRectangle(double x_point,
                        double y_point,
                        double x_upper_left_corner_rectangle,
                        double y_upper_left_corner_rectangle,
                        double x_lower_right_corner_rectangle,
                        double y_lower_right_corner_rectangle) {
  if ((x_point > x_upper_left_corner_rectangle) && (x_point < x_lower_right_corner_rectangle)) {
    if ((y_point > y_upper_left_corner_rectangle) && (y_point < y_lower_right_corner_rectangle)) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
