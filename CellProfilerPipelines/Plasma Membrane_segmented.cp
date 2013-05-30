CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\'Load desired images from folder.\'\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7CC\x3A\\Users\\Thomas Chow\\Documents\\My Box Files\\iGEM\\Automation\\Nucleus_library_check\\Library Segmented
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:3
    Text that these images have in common (case-sensitive):Blue Organelles Cell 12
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Blue
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):Green Organelles Cell 12
    Position of this image in each group:2
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Green
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):Red Organelles Cell 12
    Position of this image in each group:3
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Red
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

EnhanceEdges:[module_num:2|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Red
    Name the output image:EdgedRed
    Automatically calculate the threshold?:Yes
    Absolute threshold:.0001
    Threshold adjustment factor:1
    Select an edge-finding method:Sobel
    Select edge direction to enhance:All
    Calculate Gaussian\'s sigma automatically?:Yes
    Gaussian\'s sigma value:10
    Calculate value for low threshold automatically?:Yes
    Low threshold value:0.1

EnhanceEdges:[module_num:3|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Green
    Name the output image:EdgedGreen
    Automatically calculate the threshold?:Yes
    Absolute threshold:.0001
    Threshold adjustment factor:1
    Select an edge-finding method:Sobel
    Select edge direction to enhance:All
    Calculate Gaussian\'s sigma automatically?:Yes
    Gaussian\'s sigma value:10
    Calculate value for low threshold automatically?:Yes
    Low threshold value:0.1

EnhanceEdges:[module_num:4|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\'Sharpens the edges in the image.\'\x5D]
    Select the input image:Blue
    Name the output image:EdgedBlue
    Automatically calculate the threshold?:Yes
    Absolute threshold:.0001
    Threshold adjustment factor:1
    Select an edge-finding method:Sobel
    Select edge direction to enhance:All
    Calculate Gaussian\'s sigma automatically?:Yes
    Gaussian\'s sigma value:10
    Calculate value for low threshold automatically?:Yes
    Low threshold value:0.1

Morph:[module_num:5|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:EdgedBlue
    Name the output image:ErodedBlue
    Select the operation to perform:open
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:3

Morph:[module_num:6|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:EdgedGreen
    Name the output image:ErodedGreen
    Select the operation to perform:open
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:3

Morph:[module_num:7|svn_version:\'10300\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:EdgedRed
    Name the output image:ErodedRed
    Select the operation to perform:open
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:3

RescaleIntensity:[module_num:8|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:ErodedBlue
    Name the output image:RescaledErodedBlue
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.0,1
    Enter the desired intensity range for the final, rescaled image:1.0,2
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:9|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:ErodedRed
    Name the output image:RescaledErodedRed
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.0,1
    Enter the desired intensity range for the final, rescaled image:1.0,2
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:10|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:ErodedGreen
    Name the output image:RescaledErodedGreen
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.0,1
    Enter the desired intensity range for the final, rescaled image:1.0,2
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

MeasureImageIntensity:[module_num:11|svn_version:\'10816\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the image to measure:Blue
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:Green
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:Red
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None

IdentifyPrimaryObjects:[module_num:12|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:Green
    Name the primary objects to be identified:PlasmaMembranesGreen
    Typical diameter of objects, in pixel units (Min,Max):20,80
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Measurement
    Threshold correction factor:15
    Lower and upper bounds on threshold:0,1.0
    Approximate fraction of image covered by objects?:0.00001
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlinesGreen
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:.4
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:No
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:Intensity_StdIntensity_Green

IdentifyPrimaryObjects:[module_num:13|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:Blue
    Name the primary objects to be identified:PlasmaMembranesBlue
    Typical diameter of objects, in pixel units (Min,Max):20,80
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Measurement
    Threshold correction factor:20
    Lower and upper bounds on threshold:0,1.0
    Approximate fraction of image covered by objects?:0.00001
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlinesBlue
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:.1
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:No
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:Intensity_StdIntensity_Blue

IdentifyPrimaryObjects:[module_num:14|svn_version:\'10826\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:Red
    Name the primary objects to be identified:PlasmaMembranesRed
    Typical diameter of objects, in pixel units (Min,Max):20,80
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Measurement
    Threshold correction factor:20
    Lower and upper bounds on threshold:0,1.0
    Approximate fraction of image covered by objects?:0.00001
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlinesRed
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:.1
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:No
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:Intensity_StdIntensity_Red

MeasureObjectIntensity:[module_num:15|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:Blue
    Select objects to measure:PlasmaMembranesBlue

MeasureObjectIntensity:[module_num:16|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:Green
    Select objects to measure:PlasmaMembranesGreen

MeasureObjectIntensity:[module_num:17|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:Red
    Select objects to measure:PlasmaMembranesRed

MeasureObjectSizeShape:[module_num:18|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:PlasmaMembranesBlue
    Select objects to measure:PlasmaMembranesGreen
    Select objects to measure:PlasmaMembranesRed
    Calculate the Zernike features?:No

FilterObjects:[module_num:19|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredBlue
    Select the object to filter:PlasmaMembranesBlue
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:1300
    Filter using a maximum measurement value?:No
    Maximum value:

FilterObjects:[module_num:20|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredGreen
    Select the object to filter:PlasmaMembranesGreen
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:1300
    Filter using a maximum measurement value?:No
    Maximum value:

FilterObjects:[module_num:21|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredRed
    Select the object to filter:PlasmaMembranesRed
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:1300
    Filter using a maximum measurement value?:No
    Maximum value:

ExportToSpreadsheet:[module_num:22|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
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
    Data to export:PlasmaMembranesBlue
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:PlasmaMembranesGreen
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:PlasmaMembranesRed
    Combine these object measurements with those of the previous object?:No
    File name:DATA.csv
    Use the object name for the file name?:Yes
