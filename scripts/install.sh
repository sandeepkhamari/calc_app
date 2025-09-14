#This is used to run the cmake build and install commands
# You can run it from your build directory.
cmake -S .. -B . -DCMAKE_INSTALL_PREFIX=C:/Users/admin/CMakeFinalProject/build/install

# By default, this will build the Debug configuration on Windows.
# To build the Release configuration, use:
# cmake --build . --config Release
cmake --build .
# Running it in parallel
# cmake --build . -j 2

# Install the built files to the specified install directory
# By default, this will install the Release configuration on Windows.
cmake --install build --config=debug

#Run the test cases.
ctest --output-on-failure -C debug

# Run the test cases in parallel
#ctest -j 2 --output-on-failure -C debug

# To run tests with more detailed output, you can use the following commands:
#ctest --verbose --output-on-failure -C debug
#ctest --verbose --output-on-failure
#ctest --output-on-failure -C release
#ctest --output-on-failure
#ctest --output-on-failure
# Note: If you want to run a specific test, you can use the -R option with ctest.
# For example, to run a test named "MyTest", you can use:
# ctest -R MyTest --output-on-failure
# To run tests in parallel, you can use the -j option with ctest.
# For example, to run tests using 4 parallel jobs, you can use:
# ctest -j 4 --output-on-failure
# To clean the build directory, you can use the following command:
#rm -rf *
# To clean the install directory, you can use the following command:
#rm -rf **


# To uninstall, you can manually delete the install directory or use a script if you have one.
#rm -rf install
#./uninstall.sh

# Note: Ensure you have the necessary permissions to execute these commands and that your environment is set up correctly for CMake.
# Also, make sure to adjust paths and commands based on your specific project structure and requirements.
# This script assumes you are using a Unix-like shell. If you are on Windows, you may need to adjust the commands accordingly.
# For Windows, you might use a batch script (.bat) or PowerShell script (.ps1) instead.
# For example, in a batch script, you would replace `rm -rf` with `rmdir /s /q` and adjust other commands as needed.
# Also, ensure that CMake and your compiler are properly installed and configured in your system's PATH.
# This script is a basic example and may need to be modified to fit your specific use case.
# Always review and test scripts in a safe environment before using them in production.
# Additionally, consider adding error handling to the script to manage potential issues during the build and install
# processes. This can include checking the exit status of each command and providing informative messages to the user.
# For example, you can use `if` statements in bash to check if a command was successful and handle errors accordingly.
# Finally, remember to keep your CMakeLists.txt files updated to reflect any changes in your project structure or dependencies.
# This ensures that the build process remains smooth and that all components are correctly linked and included.
# Regularly testing the build and install process can help catch issues early and maintain a reliable development workflow.
# If you are working in a team, consider sharing this script and any relevant documentation to help others understand and use the build process effectively.
# Collaboration and clear communication are key to successful project management and development.
# Happy coding! Make sure to adapt the script as your project evolves and new requirements arise.
