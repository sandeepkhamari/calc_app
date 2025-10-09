pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                echo 'Building...'
            bat '''
                call "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"

                if EXIST build rmdir /s /q build

                mkdir build 

                cd build

                "C:\\Program Files\\CMake\\bin\\cmake.exe" -G "NMake Makefiles" -S.. -B.

                "C:\\Program Files\\CMake\\bin\\cmake.exe" --build .
                '''
            }
        }
        stage('Run Executable'){ 
           steps{
            echo 'Running the executable...'
            bat '''
                call "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"
                cd build
                dir
            '''
           }
        }
        stage('Test') {
            steps {
                echo 'Testing...'
              bat '''
                call "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"
                ctest >> test.log
              '''
            }
        }
    }
}