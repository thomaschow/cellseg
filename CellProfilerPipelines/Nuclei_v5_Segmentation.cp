CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11710

LoadImages:[module_num:1|svn_version:\'11587\'|variable_revision_number:11|show_window:False|notes:\x5B\'Load desired images from folder. For this pipeline, the optimal image file type is .tif, with four channels \x3A Red, Green, Blue, and DIC in that order.\'\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:RPL18B
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7CC\x3A\\Users\\Thomas Chow\\Documents\\My Box Files\\iGEM\\Automation\\Nucleus_library_check\\Library Segmented\\Nucleus_A
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:Yes
    Specify metadata fields to group by:
    Select subfolders to analyze:Test_Nucleus_RGBD,ZVI files
    Image count:3
    Text that these images have in common (case-sensitive):Green Organelles Cell 12
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:GreenImage
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):Blue Organelles Cell 12
    Position of this image in each group:2
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:BlueImage
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
    Name this loaded image:RedImage
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

RescaleIntensity:[module_num:2|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescale red channel.\'\x5D]
    Select the input image:RedImage
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

RescaleIntensity:[module_num:3|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescale green channel.\'\x5D]
    Select the input image:GreenImage
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

RescaleIntensity:[module_num:4|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescale blue channel.\'\x5D]
    Select the input image:BlueImage
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

IdentifyPrimaryObjects:[module_num:5|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledRed
    Name the primary objects to be identified:NucleiRed
    Typical diameter of objects, in pixel units (Min,Max):15,45
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Global
    Threshold correction factor:2
    Lower and upper bounds on threshold:.1,1.0
    Approximate fraction of image covered by objects?:.001
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:None
    Size of smoothing filter:1
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:PrimaryOutlinesRed
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:No
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
    Maximum number of objects:2
    Select the measurement to threshold with:Count_Cells

IdentifyPrimaryObjects:[module_num:6|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledGreen
    Name the primary objects to be identified:NucleiGreen
    Typical diameter of objects, in pixel units (Min,Max):15,45
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Global
    Threshold correction factor:2
    Lower and upper bounds on threshold:.1,1.0
    Approximate fraction of image covered by objects?:.001
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:None
    Size of smoothing filter:1
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:PrimaryOutlinesGreen
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:No
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
    Maximum number of objects:2
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:7|svn_version:\'10826\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:RescaledBlue
    Name the primary objects to be identified:NucleiBlue
    Typical diameter of objects, in pixel units (Min,Max):15,45
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:MoG Global
    Threshold correction factor:2
    Lower and upper bounds on threshold:.1,1.0
    Approximate fraction of image covered by objects?:.001
    Method to distinguish clumped objects:Intensity
    Method to draw dividing lines between clumped objects:None
    Size of smoothing filter:1
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:PrimaryOutlinesBlue
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:No
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
    Maximum number of objects:2
    Select the measurement to threshold with:None

MeasureObjectIntensity:[module_num:8|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledGreen
    Select objects to measure:NucleiGreen

MeasureObjectIntensity:[module_num:9|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledRed
    Select objects to measure:NucleiRed

MeasureObjectIntensity:[module_num:10|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledBlue
    Select objects to measure:NucleiBlue

MeasureObjectSizeShape:[module_num:11|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiGreen
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:12|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiBlue
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:13|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiRed
    Calculate the Zernike features?:No

FilterObjects:[module_num:14|svn_version:\'10300\'|variable_revision_number:5|show_window:True|notes:\x5B\x5D]
    Name the output objects:FilteredGreen
    Select the object to filter:NucleiGreen
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:6
    Additional object count:0
    Select the measurement to filter by:AreaShape_FormFactor
    Filter using a minimum measurement value?:Yes
    Minimum value:.65
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:200
    Filter using a maximum measurement value?:Yes
    Maximum value:1250
    Select the measurement to filter by:AreaShape_Compactness
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:1.3
    Select the measurement to filter by:AreaShape_MajorAxisLength
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:50
    Select the measurement to filter by:Intensity_IntegratedIntensity_RescaledGreen
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:390
    Select the measurement to filter by:AreaShape_MinorAxisLength
    Filter using a minimum measurement value?:Yes
    Minimum value:14.5
    Filter using a maximum measurement value?:No
    Maximum value:1

FilterObjects:[module_num:15|svn_version:\'10300\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:FilteredRed
    Select the object to filter:NucleiRed
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:6
    Additional object count:0
    Select the measurement to filter by:AreaShape_FormFactor
    Filter using a minimum measurement value?:Yes
    Minimum value:.65
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:200
    Filter using a maximum measurement value?:Yes
    Maximum value:1250
    Select the measurement to filter by:AreaShape_MajorAxisLength
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:50
    Select the measurement to filter by:AreaShape_Compactness
    Filter using a minimum measurement value?:Yes
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:1.3
    Select the measurement to filter by:Intensity_IntegratedIntensity_RescaledRed
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:390
    Select the measurement to filter by:AreaShape_MinorAxisLength
    Filter using a minimum measurement value?:Yes
    Minimum value:14.5
    Filter using a maximum measurement value?:No
    Maximum value:1

FilterObjects:[module_num:16|svn_version:\'10300\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:FilteredBlue
    Select the object to filter:NucleiBlue
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:6
    Additional object count:0
    Select the measurement to filter by:AreaShape_FormFactor
    Filter using a minimum measurement value?:Yes
    Minimum value:.65
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:200
    Filter using a maximum measurement value?:Yes
    Maximum value:1250
    Select the measurement to filter by:AreaShape_Compactness
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:1.3
    Select the measurement to filter by:AreaShape_MajorAxisLength
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:50
    Select the measurement to filter by:Intensity_IntegratedIntensity_RescaledBlue
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:390
    Select the measurement to filter by:AreaShape_MinorAxisLength
    Filter using a minimum measurement value?:Yes
    Minimum value:14.5
    Filter using a maximum measurement value?:No
    Maximum value:1

MeasureObjectIntensity:[module_num:17|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledBlue
    Select objects to measure:FilteredBlue

MeasureObjectIntensity:[module_num:18|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledGreen
    Select objects to measure:FilteredGreen

MeasureObjectIntensity:[module_num:19|svn_version:\'10816\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:RescaledRed
    Select objects to measure:FilteredRed

MeasureObjectSizeShape:[module_num:20|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:FilteredGreen
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:21|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:FilteredBlue
    Calculate the Zernike features?:No

MeasureObjectSizeShape:[module_num:22|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:FilteredRed
    Calculate the Zernike features?:No

ExportToSpreadsheet:[module_num:23|svn_version:\'10880\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:Yes
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Default Output Folder sub-folder\x7CNucleus_Library_Check
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:NucleiRed\x7CIntensity_StdIntensityEdge_RescaledRed,NucleiRed\x7CIntensity_MinIntensity_RescaledRed,NucleiRed\x7CIntensity_IntegratedIntensityEdge_RescaledRed,NucleiRed\x7CIntensity_StdIntensity_RescaledRed,NucleiRed\x7CIntensity_MassDisplacement_RescaledRed,NucleiRed\x7CIntensity_UpperQuartileIntensity_RescaledRed,NucleiRed\x7CIntensity_LowerQuartileIntensity_RescaledRed,NucleiRed\x7CIntensity_MinIntensityEdge_RescaledRed,NucleiRed\x7CIntensity_MeanIntensity_RescaledRed,NucleiRed\x7CIntensity_MeanIntensityEdge_RescaledRed,NucleiRed\x7CIntensity_MaxIntensity_RescaledRed,NucleiRed\x7CIntensity_MedianIntensity_RescaledRed,NucleiRed\x7CIntensity_IntegratedIntensity_RescaledRed,NucleiRed\x7CIntensity_MaxIntensityEdge_RescaledRed,NucleiRed\x7CAreaShape_Perimeter,NucleiRed\x7CAreaShape_FormFactor,NucleiRed\x7CAreaShape_Orientation,NucleiRed\x7CAreaShape_Area,NucleiRed\x7CAreaShape_Solidity,NucleiRed\x7CAreaShape_EulerNumber,NucleiRed\x7CAreaShape_Compactness,NucleiRed\x7CAreaShape_Extent,NucleiRed\x7CAreaShape_Eccentricity,NucleiRed\x7CAreaShape_MinorAxisLength,NucleiRed\x7CAreaShape_MajorAxisLength,NucleiRed\x7CAreaShape_Center_Y,NucleiRed\x7CAreaShape_Center_X,FilteredBlue\x7CIntensity_StdIntensityEdge_RescaledBlue,FilteredBlue\x7CIntensity_MinIntensity_RescaledBlue,FilteredBlue\x7CIntensity_IntegratedIntensityEdge_RescaledBlue,FilteredBlue\x7CIntensity_StdIntensity_RescaledBlue,FilteredBlue\x7CIntensity_MassDisplacement_RescaledBlue,FilteredBlue\x7CIntensity_UpperQuartileIntensity_RescaledBlue,FilteredBlue\x7CIntensity_LowerQuartileIntensity_RescaledBlue,FilteredBlue\x7CIntensity_MinIntensityEdge_RescaledBlue,FilteredBlue\x7CIntensity_MeanIntensity_RescaledBlue,FilteredBlue\x7CIntensity_MeanIntensityEdge_RescaledBlue,FilteredBlue\x7CIntensity_MaxIntensity_RescaledBlue,FilteredBlue\x7CIntensity_MedianIntensity_RescaledBlue,FilteredBlue\x7CIntensity_IntegratedIntensity_RescaledBlue,FilteredBlue\x7CIntensity_MaxIntensityEdge_RescaledBlue,FilteredBlue\x7CAreaShape_Perimeter,FilteredBlue\x7CAreaShape_FormFactor,FilteredBlue\x7CAreaShape_Orientation,FilteredBlue\x7CAreaShape_Area,FilteredBlue\x7CAreaShape_Solidity,FilteredBlue\x7CAreaShape_EulerNumber,FilteredBlue\x7CAreaShape_Compactness,FilteredBlue\x7CAreaShape_Extent,FilteredBlue\x7CAreaShape_Eccentricity,FilteredBlue\x7CAreaShape_MinorAxisLength,FilteredBlue\x7CAreaShape_MajorAxisLength,FilteredBlue\x7CAreaShape_Center_Y,FilteredBlue\x7CAreaShape_Center_X,NucleiBlue\x7CIntensity_StdIntensityEdge_RescaledBlue,NucleiBlue\x7CIntensity_MinIntensity_RescaledBlue,NucleiBlue\x7CIntensity_IntegratedIntensityEdge_RescaledBlue,NucleiBlue\x7CIntensity_StdIntensity_RescaledBlue,NucleiBlue\x7CIntensity_MassDisplacement_RescaledBlue,NucleiBlue\x7CIntensity_UpperQuartileIntensity_RescaledBlue,NucleiBlue\x7CIntensity_LowerQuartileIntensity_RescaledBlue,NucleiBlue\x7CIntensity_MinIntensityEdge_RescaledBlue,NucleiBlue\x7CIntensity_MeanIntensity_RescaledBlue,NucleiBlue\x7CIntensity_MeanIntensityEdge_RescaledBlue,NucleiBlue\x7CIntensity_MaxIntensity_RescaledBlue,NucleiBlue\x7CIntensity_MedianIntensity_RescaledBlue,NucleiBlue\x7CIntensity_IntegratedIntensity_RescaledBlue,NucleiBlue\x7CIntensity_MaxIntensityEdge_RescaledBlue,NucleiBlue\x7CAreaShape_Perimeter,NucleiBlue\x7CAreaShape_FormFactor,NucleiBlue\x7CAreaShape_Orientation,NucleiBlue\x7CAreaShape_Area,NucleiBlue\x7CAreaShape_Solidity,NucleiBlue\x7CAreaShape_EulerNumber,NucleiBlue\x7CAreaShape_Compactness,NucleiBlue\x7CAreaShape_Extent,NucleiBlue\x7CAreaShape_Eccentricity,NucleiBlue\x7CAreaShape_MinorAxisLength,NucleiBlue\x7CAreaShape_MajorAxisLength,NucleiBlue\x7CAreaShape_Center_Y,NucleiBlue\x7CAreaShape_Center_X,FilteredGreen\x7CIntensity_StdIntensityEdge_RescaledGreen,FilteredGreen\x7CIntensity_MinIntensity_RescaledGreen,FilteredGreen\x7CIntensity_IntegratedIntensityEdge_RescaledGreen,FilteredGreen\x7CIntensity_StdIntensity_RescaledGreen,FilteredGreen\x7CIntensity_MassDisplacement_RescaledGreen,FilteredGreen\x7CIntensity_UpperQuartileIntensity_RescaledGreen,FilteredGreen\x7CIntensity_LowerQuartileIntensity_RescaledGreen,FilteredGreen\x7CIntensity_MinIntensityEdge_RescaledGreen,FilteredGreen\x7CIntensity_MeanIntensity_RescaledGreen,FilteredGreen\x7CIntensity_MeanIntensityEdge_RescaledGreen,FilteredGreen\x7CIntensity_MaxIntensity_RescaledGreen,FilteredGreen\x7CIntensity_MedianIntensity_RescaledGreen,FilteredGreen\x7CIntensity_IntegratedIntensity_RescaledGreen,FilteredGreen\x7CIntensity_MaxIntensityEdge_RescaledGreen,FilteredGreen\x7CAreaShape_Perimeter,FilteredGreen\x7CAreaShape_FormFactor,FilteredGreen\x7CAreaShape_Orientation,FilteredGreen\x7CAreaShape_Area,FilteredGreen\x7CAreaShape_Solidity,FilteredGreen\x7CAreaShape_EulerNumber,FilteredGreen\x7CAreaShape_Compactness,FilteredGreen\x7CAreaShape_Extent,FilteredGreen\x7CAreaShape_Eccentricity,FilteredGreen\x7CAreaShape_MinorAxisLength,FilteredGreen\x7CAreaShape_MajorAxisLength,FilteredGreen\x7CAreaShape_Center_Y,FilteredGreen\x7CAreaShape_Center_X,FilteredRed\x7CIntensity_StdIntensityEdge_RescaledRed,FilteredRed\x7CIntensity_MinIntensity_RescaledRed,FilteredRed\x7CIntensity_IntegratedIntensityEdge_RescaledRed,FilteredRed\x7CIntensity_StdIntensity_RescaledRed,FilteredRed\x7CIntensity_MassDisplacement_RescaledRed,FilteredRed\x7CIntensity_UpperQuartileIntensity_RescaledRed,FilteredRed\x7CIntensity_LowerQuartileIntensity_RescaledRed,FilteredRed\x7CIntensity_MinIntensityEdge_RescaledRed,FilteredRed\x7CIntensity_MeanIntensity_RescaledRed,FilteredRed\x7CIntensity_MeanIntensityEdge_RescaledRed,FilteredRed\x7CIntensity_MaxIntensity_RescaledRed,FilteredRed\x7CIntensity_MedianIntensity_RescaledRed,FilteredRed\x7CIntensity_IntegratedIntensity_RescaledRed,FilteredRed\x7CIntensity_MaxIntensityEdge_RescaledRed,FilteredRed\x7CAreaShape_Perimeter,FilteredRed\x7CAreaShape_FormFactor,FilteredRed\x7CAreaShape_Orientation,FilteredRed\x7CAreaShape_Area,FilteredRed\x7CAreaShape_Solidity,FilteredRed\x7CAreaShape_EulerNumber,FilteredRed\x7CAreaShape_Compactness,FilteredRed\x7CAreaShape_Extent,FilteredRed\x7CAreaShape_Eccentricity,FilteredRed\x7CAreaShape_MinorAxisLength,FilteredRed\x7CAreaShape_MajorAxisLength,FilteredRed\x7CAreaShape_Center_Y,FilteredRed\x7CAreaShape_Center_X,NucleiGreen\x7CIntensity_StdIntensityEdge_RescaledGreen,NucleiGreen\x7CIntensity_MinIntensity_RescaledGreen,NucleiGreen\x7CIntensity_IntegratedIntensityEdge_RescaledGreen,NucleiGreen\x7CIntensity_StdIntensity_RescaledGreen,NucleiGreen\x7CIntensity_MassDisplacement_RescaledGreen,NucleiGreen\x7CIntensity_UpperQuartileIntensity_RescaledGreen,NucleiGreen\x7CIntensity_LowerQuartileIntensity_RescaledGreen,NucleiGreen\x7CIntensity_MinIntensityEdge_RescaledGreen,NucleiGreen\x7CIntensity_MeanIntensity_RescaledGreen,NucleiGreen\x7CIntensity_MeanIntensityEdge_RescaledGreen,NucleiGreen\x7CIntensity_MaxIntensity_RescaledGreen,NucleiGreen\x7CIntensity_MedianIntensity_RescaledGreen,NucleiGreen\x7CIntensity_IntegratedIntensity_RescaledGreen,NucleiGreen\x7CIntensity_MaxIntensityEdge_RescaledGreen,NucleiGreen\x7CAreaShape_Perimeter,NucleiGreen\x7CAreaShape_FormFactor,NucleiGreen\x7CAreaShape_Orientation,NucleiGreen\x7CAreaShape_Area,NucleiGreen\x7CAreaShape_Solidity,NucleiGreen\x7CAreaShape_EulerNumber,NucleiGreen\x7CAreaShape_Compactness,NucleiGreen\x7CAreaShape_Extent,NucleiGreen\x7CAreaShape_Eccentricity,NucleiGreen\x7CAreaShape_MinorAxisLength,NucleiGreen\x7CAreaShape_MajorAxisLength,NucleiGreen\x7CAreaShape_Center_Y,NucleiGreen\x7CAreaShape_Center_X
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
