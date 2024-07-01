## This code will delete all the files created after running the cpp files
import os
import time

def delete_matching_files():
    # Get the directory where the script is located
    script_directory = os.path.dirname(os.path.realpath(__file__))
     # Get a list of all files in the directory
    files = os.listdir(script_directory)
        
    # Create a set of all cpp files without their extensions
    cpp_files = {os.path.splitext(file)[0] for file in files if file.endswith('.c')}
        
    # Iterate over all files and delete the ones that match the cpp file names
    for file in files:
        filename, ext = os.path.splitext(file)
        if filename in cpp_files and ext != '.c':
            file_to_delete = os.path.join(script_directory, file)
            os.remove(file_to_delete)
            print(f'Deleted file: {file_to_delete}')

# Call the function
delete_matching_files()
