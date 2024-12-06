## to build the docker image 
`docker build -t cpp-app .`

## to run the container 
`docker run -it cpp-app`

## stop the container 
`docker stop cpp-container`

## if did some changes in the code then rebuild the image 
`docker stop cpp-container`


## compiling the program
`g++ -std=c++17 part01.cpp -o prog`


## running contaier with a mount of local address
`docker run -it --rm -v $(pwd):/app cpp-app`