Multivariate Data Anonymization Program

Authors: Annick E. Iroukora, Ayad Haladi

This program aims to anonymize already partially anonymized medical data while preserving essential information and ensuring patient confidentiality. The data is loaded from text files annotated with temporal events, then anonymized using calculated means for each event. Randomization can also be performed after mean replacement. The anonymized data is then written to a CSV file for later use.

Installation

To install and compile the program, follow the steps below:

    Make sure you have make installed on your system.
    Download the contents of the Zip file into a directory of your choice.
    Navigate to the directory containing the downloaded files.
    Run the make command.
    Upon completion, the program will be available in a folder named "exe".

    Execution

    To execute the program, you have the choice between direct execution or via a Python script.
    Direct Execution:

    Use the following command:

    ./main input_directory output_directory first last random_first random_last

    Multivariate Data Anonymization Program

    Authors: Annick E. Iroukora, Ayad Haladi

    This program aims to anonymize already partially anonymized medical data while preserving essential information and ensuring patient confidentiality. The data is loaded from text files annotated with temporal events, then anonymized using calculated means for each event. Randomization can also be performed after mean replacement. The anonymized data is then written to a CSV file for later use.
    Installation

    To install and compile the program, follow the steps below:

        Make sure you have make installed on your system.
        Download the contents of the Zip file into a directory of your choice.
        Navigate to the directory containing the downloaded files.
        Run the make command.
        Upon completion, the program will be available in a folder named bin.

    Execution

    To execute the program, you have the choice between direct execution or via a Python script.
    Direct Execution:

    Use the following command:

    sql

    ./main input_directory output_directory first last random_first random_last

    Where:

        input_directory corresponds to the folder containing the inputs.
        output_directory corresponds to the output folder.
        first corresponds to the identifier of the first patient.
        last corresponds to the identifier of the last patient.
        random_first and random_last correspond to the range for randomization.

    (You will need to navigate to the directory containing the executable)

    Execution via Python script:

    For this method, please fill in the my_param.txt file with the necessary parameters beforehand, then launch the Python script with the command:
    python3 launch_me.py

    first: number of the first patient to anonymize
    last: number of the last patient to anonymize
    random_first: lower bound for random
    random_last: upper bound for random

    Input File:

    The input files must be in '.txt' format. For each patient, we should have:

        a file on temporal data
        a file on event traces.
        These files should be in a folder named "data".

    Output File:

    The output files will be in the annony_meth folder. The outputs will be provided in '.csv' format.
    Toy Script:

    A simplified training script is provided in the example_meth folder. By running the script in this folder with the command python3 example_joy.py, the script will execute the method on a reduced dataset of 10 patients. No parameter files are required for this example.
    Analyzing Anonymized Data with Python:

    This guide helps you set up and run a Python script to analyze anonymized and real data, calculating DTW dissimilarities, performing statistical tests, and visualizing the results.
    Prerequisites:

        Python 3.x installed
        Required Python libraries: numpy, pandas, matplotlib, seaborn, tslearn, scipy
        You can install them via pip: pip install numpy pandas matplotlib seaborn tslearn scipy

    Folder Structure:

        data/: Contains real time series (named 1_series.csv, 2_series.csv, ..., 1000_series.csv).
        gener_simulated_data_anonymisees/: Contains corresponding anonymized time series.
        gener_simulated_data_analysees/: Output directory where results will be saved.

    Python Script File:

    The main script "anon_analysis1.py" and "anon_analysis2.py"  contains the code for the analysis.
    Execution Steps:

        Ensure all prerequisites are installed and data is placed in the correct folders.
        Open a terminal or command prompt.
        Navigate to the directory containing the script "anon_analysis1.py".
        Execute the script using the command: python3 anon_analysis1.py.
        Then execute the script python3 anon_analysis2.py.
        The scripts will load the data, perform the analyses, and save the results in the gener_simulated_data_analysees/ directory.

same processe for the toy's data.
    Results:

        DTW dissimilarities, descriptive statistics, and statistical test results will be saved as CSV files in the output directory.
        A violin plot of normalized dissimilarities will also be saved for quick visualization.
