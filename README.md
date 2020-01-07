# LearnCpp

# How to deploy glfw
  - 安装X11: sudo apt-get install libx11-dev
  - 安装RandR: sudo apt-get install libxrandr-dev
  - 安装Xinerama: sudo apt-get install libxinerama-dev
  - 安装Xcursor: sudo apt-get install libxcursor-dev
  - 安装OpenGL: sudo apt-get install libglu1-mesa-dev

  - compile .a: 
    - mkdir build
    - cmake ..
    - make
  - compile .so:
    - cmake -DBUILD_SHARED_LIBS=ON ..
    - make 
