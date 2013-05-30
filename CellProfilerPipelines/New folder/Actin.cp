CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B"Load the images by matching files in the folder against the text pattern for each stain\x3A \'hoe\' for nuclei, \'h2ax\' for the histone foci stain image. The two images together comprise an image set."\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Elsewhere...\x7CC\x3A\\Users\\Thomas Chow\\Documents\\My Box Files\\iGEM\\Automation\\Actin images
    Check image sets for missing or duplicate files?:No
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:1
    Text that these images have in common (case-sensitive):yTC003-mid
    Position of this image in each group:hoe
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:None
    Type the regular expression that finds metadata in the subfolder path:None
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:2
    Load the input as images or objects?:Images
    Name this loaded image:Image
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes

ColorToGray:[module_num:2|svn_version:\'10318\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Image
    Conversion method:Combine
    Image type\x3A:RGB
    Name the output image:OrigGray
    Relative weight of the red channel:1
    Relative weight of the green channel:1
    Relative weight of the blue channel:1
    Convert red to gray?:Yes
    Name the output image:OrigRed
    Convert green to gray?:Yes
    Name the output image:OrigGreen
    Convert blue to gray?:Yes
    Name the output image:OrigBlue
    Channel count:2
    Channel number\x3A:Red\x3A 1
    Relative weight of the channel:1
    Image name\x3A:Channel1
    Channel number\x3A:Green\x3A 2
    Relative weight of the channel:1
    Image name\x3A:Channel2

ColorToGray:[module_num:3|svn_version:\'10318\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Image
    Conversion method:Split
    Image type\x3A:Channels
    Name the output image:OrigGray
    Relative weight of the red channel:1
    Relative weight of the green channel:1
    Relative weight of the blue channel:1
    Convert red to gray?:Yes
    Name the output image:OrigRed
    Convert green to gray?:Yes
    Name the output image:OrigGreen
    Convert blue to gray?:Yes
    Name the output image:OrigBlue
    Channel count:3
    Channel number\x3A:Red\x3A 1
    Relative weight of the channel:1
    Image name\x3A:Red
    Channel number\x3A:Green\x3A 2
    Relative weight of the channel:1
    Image name\x3A:Green
    Channel number\x3A:Blue\x3A 3
    Relative weight of the channel:1
    Image name\x3A:DIC

EnhanceEdges:[module_num:4|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:DIC
    Name the output image:EdgedActinDIC
    Automatically calculate the threshold?:Yes
    Absolute threshold:0.2
    Threshold adjustment factor:.5
    Select an edge-finding method:Canny
    Select edge direction to enhance:All
    Calculate Gaussian\'s sigma automatically?:Yes
    Gaussian\'s sigma value:10
    Calculate value for low threshold automatically?:Yes
    Low threshold value:0.1

RescaleIntensity:[module_num:5|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:EdgedActinDIC
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

Morph:[module_num:6|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:RescaledDIC
    Name the output image:MorphDIC
    Select the operation to perform:close
    Number of times to repeat operation:Forever
    Repetition number:2
    Scale:35

IdentifyPrimaryObjects:[module_num:7|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\'Identify the nuclei from the nuclear stain image. \'\x5D]
    Select the input image:MorphDIC
    Name the primary objects to be identified:Cells
    Typical diameter of objects, in pixel units (Min,Max):30,300
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:Yes
    Discard objects touching the border of the image?:No
    Select the thresholding method:Otsu Adaptive
    Threshold correction factor:1
    Lower and upper bounds on threshold:0,1
    Approximate fraction of image covered by objects?:10%
    Method to distinguish clumped objects:Shape
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:1
    Suppress local maxima that are closer than this minimum allowed distance:5
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:None
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:Otsu Global
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

MaskImage:[module_num:8|svn_version:\'10428\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:Red
    Name the output image:MaskRed
    Use objects or an image as a mask?:Objects
    Select object for mask:Cells
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:9|svn_version:\'10428\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:Green
    Name the output image:MaskGreen
    Use objects or an image as a mask?:Objects
    Select object for mask:Cells
    Select image for mask:None
    Invert the mask?:No

RescaleIntensity:[module_num:10|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:MaskGreen
    Name the output image:RescaledActinGreen
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

RescaleIntensity:[module_num:11|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:MaskRed
    Name the output image:RescaledActinRed
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

IdentifyPrimaryObjects:[module_num:12|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledActinGreen
    Name the primary objects to be identified:ActinGreen
    Typical diameter of objects, in pixel units (Min,Max):3,20
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:RobustBackground Adaptive
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.0,1.0
    Approximate fraction of image covered by objects?:10%
    Method to distinguish clumped objects:Laplacian of Gaussian
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:1
    Suppress local maxima that are closer than this minimum allowed distance:1
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:No
    Manual threshold:.1
    Select binary image:Otsu PerObject
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:13|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledActinRed
    Name the primary objects to be identified:ActinRed
    Typical diameter of objects, in pixel units (Min,Max):3,20
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:RobustBackground Adaptive
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.0,1.0
    Approximate fraction of image covered by objects?:10%
    Method to distinguish clumped objects:Laplacian of Gaussian
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:1
    Suppress local maxima that are closer than this minimum allowed distance:1
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:No
    Manual threshold:.1
    Select binary image:Otsu PerObject
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

MeasureObjectSizeShape:[module_num:14|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:ActinGreen
    Select objects to measure:ActinRed
    Calculate the Zernike features?:No

ExportToSpreadsheet:[module_num:15|svn_version:\'10880\'|variable_revision_number:7|show_window:True|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:No
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:No
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Output Folder sub-folder\x7CNucleus_Library_Check_Properties
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:
    Data to export:ActinGreen
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:ActinRed
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
