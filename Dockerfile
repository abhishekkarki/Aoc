# use a base image with build tools
FROM ubuntu:22.04

# updata and install required compilers and build tools
RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    gcc \
    g++ \
    cmake \
    git \
    vim \
    && apt-get clean 

# Set the working directory inside the container
WORKDIR /app

# Copy your project into the container
COPY . /app

# Run cmake to configure and build the project (if applicable)
# RUN cmake . && make

# Set default command (optional, for interactive use)
CMD ["/bin/bash"]
