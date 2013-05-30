CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Elsewhere...\x7CD\x3A\\My Stuff\\My Box Files\\iGEM(masakiyamada@berkeley.edu)\\Automation\\Images to Process
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:1
    Text that these images have in common (case-sensitive):yRC030C- mid.zvi - C=2
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Load the input as images or objects?:Images
    Name this loaded image:yeast
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes

EnhanceEdges:[module_num:2|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:yeast
    Name the output image:EdgedImage
    Automatically calculate the threshold?:Yes
    Absolute threshold:0.2
    Threshold adjustment factor:1
    Select an edge-finding method:Sobel
    Select edge direction to enhance:All
    Calculate Gaussian\'s sigma automatically?:Yes
    Gaussian\'s sigma value:10
    Calculate value for low threshold automatically?:Yes
    Low threshold value:0.1

EnhanceOrSuppressFeatures:[module_num:3|svn_version:\'10591\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:EdgedImage
    Name the output image:FilteredBlue
    Select the operation:Enhance
    Feature size:10
    Feature type:Dark holes
    Range of hole sizes:1,60

RescaleIntensity:[module_num:4|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:EdgedImage
    Name the output image:RescaledDIC
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

EnhanceEdges:[module_num:5|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:RescaledDIC
    Name the output image:EdgedDIC
    Automatically calculate the threshold?:Yes
    Absolute threshold:0.2
    Threshold adjustment factor:1
    Select an edge-finding method:Sobel
    Select edge direction to enhance:All
    Calculate Gaussian\'s sigma automatically?:Yes
    Gaussian\'s sigma value:10
    Calculate value for low threshold automatically?:Yes
    Low threshold value:0.1

Morph:[module_num:6|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:EdgedDIC
    Name the output image:MorphDIC
    Select the operation to perform:close
    Number of times to repeat operation:Forever
    Repetition number:6
    Scale:10

IdentifyPrimaryObjects:[module_num:7|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:MorphDIC
    Name the primary objects to be identified:Yeast
    Typical diameter of objects, in pixel units (Min,Max):50,300
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:RobustBackground Adaptive
    Threshold correction factor: 1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:3
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None
