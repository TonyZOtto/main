# ozSandbox Notes
Initial Draft 20240706aho

## Setup

* Set Current Subject Index Photo based upon Grey Photo
  * Luminance stretch with 1/16 inside below and above
  * Element Segmentation
    * Lowest: Bronze
    * Low Half: Liquid
    * Middle: Silver
    * High Half: Solids
    * Highest: Gold
    
## Step

* Move old Displayed photo to Current Subject Index Photo
* Calculate QTransform from Flip/Rotate
* Source from transformed coordinates and neighbors in current photo
  * Fill above neighbors with edge of boundry
  * Iterate rows within borders
    * Fill left neighbors with edge of boundry
    * Iterate cols within borders
    * Get Input Element
      * Calculate New Element based upon transformed coordinate and neighbors
      * Write New to output photo row
    * emit row finished
      * to slot
        * Extract QPixmap from Output Index Photo
        * Post to Scene Output layer
        * Remove transparency for this row
* At end of rows, emit frame finished
  * if Auto, wait specfied time and process next flip/angle
  * UI idle
    * process Actions for angle changes or file open/next/quit
    * Initiate processing on rotate/flip action
    
