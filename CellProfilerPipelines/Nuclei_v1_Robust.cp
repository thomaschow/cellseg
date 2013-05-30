CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\'Load desired images from folder.\'\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Default Input Folder sub-folder\x7CDocuments\\My Box Files\\iGEM\\Automation\\Nucleus_library_check\\Library ( .tiff format)
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:1
    Text that these images have in common (case-sensitive):Nucleus_A
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Image
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

ColorToGray:[module_num:2|svn_version:\'10318\'|variable_revision_number:2|show_window:False|notes:\x5B\'Convert the original colored images  to grayscale, with all channels merged.\'\x5D]
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
    Channel count:1
    Channel number\x3A:Red\x3A 1
    Relative weight of the channel:1
    Image name\x3A:Channel1

ColorToGray:[module_num:3|svn_version:\'10318\'|variable_revision_number:2|show_window:False|notes:\x5B\'Now convert the colored images to grayscale, but separating each channel into red, green, and blue.\'\x5D]
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
    Channel count:4
    Channel number\x3A:Red\x3A 1
    Relative weight of the channel:1
    Image name\x3A:Red
    Channel number\x3A:Green\x3A 2
    Relative weight of the channel:1
    Image name\x3A:Green
    Channel number\x3A:Blue\x3A 3
    Relative weight of the channel:1
    Image name\x3A:Blue
    Channel number\x3A:Alpha\x3A 4
    Relative weight of the channel:1
    Image name\x3A:Channel4

GrayToColor:[module_num:4|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Red
    Select the input image to be colored green:Green
    Select the input image to be colored blue:Blue
    Name the output image:ColorImage
    Relative weight for the red image:1
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:Leave this black
    Select the input image to be colored magenta:Leave this black
    Select the input image to be colored yellow:Leave this black
    Select the input image that determines brightness:Leave this black
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

GrayToColor:[module_num:5|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:Green
    Select the input image to be colored blue:Leave this black
    Name the output image:ColorImage
    Relative weight for the red image:1
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:Leave this black
    Select the input image to be colored magenta:Leave this black
    Select the input image to be colored yellow:Leave this black
    Select the input image that determines brightness:Leave this black
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

GrayToColor:[module_num:6|svn_version:\'10341\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:Blue
    Name the output image:ColorImage
    Relative weight for the red image:1
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:Leave this black
    Select the input image to be colored magenta:Leave this black
    Select the input image to be colored yellow:Leave this black
    Select the input image that determines brightness:Leave this black
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

RescaleIntensity:[module_num:7|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:OrigGray
    Name the output image:RescaledComposite
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

RescaleIntensity:[module_num:8|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Red
    Name the output image:RescaledRed
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

RescaleIntensity:[module_num:9|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Green
    Name the output image:RescaledGreen
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

RescaleIntensity:[module_num:10|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Blue
    Name the output image:RescaledBlue
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

EnhanceOrSuppressFeatures:[module_num:11|svn_version:\'10591\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:RescaledGreen
    Name the output image:EnhancedGreen
    Select the operation:Enhance
    Feature size:50
    Feature type:Speckles
    Range of hole sizes:1,10

EnhanceOrSuppressFeatures:[module_num:12|svn_version:\'10591\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:RescaledBlue
    Name the output image:EnhancedBlue
    Select the operation:Enhance
    Feature size:50
    Feature type:Speckles
    Range of hole sizes:1,10

EnhanceOrSuppressFeatures:[module_num:13|svn_version:\'10591\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:RescaledRed
    Name the output image:EnhancedRed
    Select the operation:Enhance
    Feature size:50
    Feature type:Speckles
    Range of hole sizes:1,10

EnhanceOrSuppressFeatures:[module_num:14|svn_version:\'10591\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:RescaledComposite
    Name the output image:EnhancedComposite
    Select the operation:Enhance
    Feature size:50
    Feature type:Speckles
    Range of hole sizes:1,10

ApplyThreshold:[module_num:15|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:EnhancedBlue
    Name the output image:ThreshBlue
    Select the output image type:Grayscale
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:RobustBackground Adaptive
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.2,0.7
    Threshold correction factor:3
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:16|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:EnhancedGreen
    Name the output image:ThreshGreen
    Select the output image type:Grayscale
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:RobustBackground Adaptive
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.2,.7
    Threshold correction factor:3
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:17|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:EnhancedRed
    Name the output image:ThreshRed
    Select the output image type:Grayscale
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:RobustBackground Adaptive
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.2,.7
    Threshold correction factor:3
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:18|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:RescaledComposite
    Name the primary objects to be identified:NucleiComposite
    Typical diameter of objects, in pixel units (Min,Max):15,50
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:RobustBackground Adaptive
    Threshold correction factor:3
    Lower and upper bounds on threshold:0.2,0.7
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Shape
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:3
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:.65
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:19|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledRed
    Name the primary objects to be identified:NucleiRed
    Typical diameter of objects, in pixel units (Min,Max):15,35
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Adaptive
    Threshold correction factor:2
    Lower and upper bounds on threshold:0,0.7
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:3
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:.65
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:20|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledGreen
    Name the primary objects to be identified:NucleiGreen
    Typical diameter of objects, in pixel units (Min,Max):15,35
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Adaptive
    Threshold correction factor:2
    Lower and upper bounds on threshold:0,0.7
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:3
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlinesGreen
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:.65
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:21|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledBlue
    Name the primary objects to be identified:NucleiBlue
    Typical diameter of objects, in pixel units (Min,Max):15,35
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Adaptive
    Threshold correction factor:2
    Lower and upper bounds on threshold:0,0.7
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:3
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:.65
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

OverlayOutlines:[module_num:22|svn_version:\'10672\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:Green
    Name the output image:GreenGrayOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:PrimaryOutlinesGreen
    Select outline color:Red

MeasureObjectIntensity:[module_num:23|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledGreen
    Select objects to measure:NucleiGreen

MeasureObjectIntensity:[module_num:24|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledRed
    Select objects to measure:NucleiRed

MeasureObjectIntensity:[module_num:25|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledBlue
    Select objects to measure:NucleiBlue

MeasureObjectIntensity:[module_num:26|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledComposite
    Select objects to measure:NucleiComposite

MeasureObjectSizeShape:[module_num:27|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiComposite
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:28|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiGreen
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:29|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiBlue
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:30|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiRed
    Calculate the Zernike features?:No

FilterObjects:[module_num:31|svn_version:\'10300\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:FilteredComposite
    Select the object to filter:NucleiComposite
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:0
    Select the measurement to filter by:AreaShape_FormFactor
    Filter using a minimum measurement value?:Yes
    Minimum value:.6
    Filter using a maximum measurement value?:Yes
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:150
    Filter using a maximum measurement value?:No
    Maximum value:2000

FilterObjects:[module_num:32|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredGreen
    Select the object to filter:NucleiGreen
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:0
    Select the measurement to filter by:AreaShape_FormFactor
    Filter using a minimum measurement value?:Yes
    Minimum value:.6
    Filter using a maximum measurement value?:Yes
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:150
    Filter using a maximum measurement value?:No
    Maximum value:1

FilterObjects:[module_num:33|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredRed
    Select the object to filter:NucleiRed
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:0
    Select the measurement to filter by:AreaShape_FormFactor
    Filter using a minimum measurement value?:Yes
    Minimum value:.6
    Filter using a maximum measurement value?:Yes
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:150
    Filter using a maximum measurement value?:No
    Maximum value:1

FilterObjects:[module_num:34|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredBlue
    Select the object to filter:NucleiBlue
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:0
    Select the measurement to filter by:AreaShape_FormFactor
    Filter using a minimum measurement value?:Yes
    Minimum value:.6
    Filter using a maximum measurement value?:Yes
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:150
    Filter using a maximum measurement value?:No
    Maximum value:1

MeasureObjectSizeShape:[module_num:35|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:FilteredComposite
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:36|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:FilteredGreen
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:37|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:FilteredBlue
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:38|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:FilteredRed
    Calculate the Zernike features?:No

ExportToSpreadsheet:[module_num:39|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:No
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Input Folder sub-folder\x7CDocuments\\\\My Box Files\\\\iGEM\\\\Automation\\\\Nucleus_library_check\\\\Library ( .tiff format)\\\\Nucleus_Library_Check
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:
    Data to export:FilteredBlue
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:FilteredGreen
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:FilteredRed
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:FilteredComposite
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:NucleiComposite
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:NucleiGreen
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:NucleiRed
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:NucleiBlue
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
