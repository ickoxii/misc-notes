# Configuring an Ubuntu VM on Docker

## Update:

```bash
# Call 'run' with certain flags on the distro name
docker run -dit ubuntu
# Search for the process you just created
docker ps -a
# Use exec with -it flags to launch interactive terminal
# 'campassionate_cray' was the name of the ubuntu process created earlier
docker exec -it compassionate_cray bash
```

Thank you to Libo Sun for the video: 
[Link](https://www.youtube.com/watch?v=idtIeTF9LsI)

## Ubuntu-vm on MacOS M1 via Docker

```bash
# 1. Open Docker Desktop to start the Docker daemon

# 2. Install Ubuntu image
docker image ls     # Prints all images currently loaded in Docker
docker pull ubuntu  # Pull the latest Ubuntu image into Docker
docker image ls     # Verify Ubuntu image got pulled

# 3. Start running the image in Docker Desktop
    # Find the ubuntu image in 'images'
    # Click 'Run'
    # You can specify a name for you Ubuntu container or let Docker
        # randomly generate one for you

# 4. Start your container in Docker Desktop
    # Find the container in 'Containers/Apps' and verify it is running

# 5. Go back to terminal and search your Containers
docker ps -a

# 6. Start your container
docker start your_container_name

# 7. Login to your container
docker exec -it your_container_name bash

# 8. You should now be in your container
ls  # Check you are in container

# 9. Lets make sure we are on the latest version
apt-get update

# 10. Can we ping a website?
ping www.google.com

# 11. If no:
apt-get install iputils-ping
ping www.google.com
```

## 1. Getting Started with Docker Desktop

```bash
# 1. Open Docker Desktop to start the Docker daemon
```

To begin, we will be utilizing 
[Docker Desktop](https://www.docker.com/products/docker-desktop/). You can
visit their website to download the correct version for your operating system.  

Once installed, open Docker Desktop so that you can use `docker` commands in 
the terminal.

## 2. Install Ubuntu Image

```bash
docker image ls     # Prints all images currently loaded in Docker
docker pull ubuntu  # Pull the latest Ubuntu image into Docker
docker image ls     # Verify Ubuntu image got pulled
```

We use the command `docker image ls` to list all of the images currently in 
our docker application. We use the command `docker pull` followed by our 
specified image to pull that image into Docker.

## 3. Start Running the Image in Docker Desktop

Go back to Docker Desktop and go to the 'Images' section. Look for the image 
you just downloaded (ubuntu), and click 'Run'. This will open up a prompt 
allowing you to change certain settings. I don't know what the other settings 
do but you can change the image name to something. I would choose something 
like 'ubuntu-vm' or 'ubuntu-docker'.  

If you do not specify a name, Docker will randomly choose one for you.

## 4. Start Your Container in Docker Desktop

While in Docker Desktop, go to the 'Containers/Apps' section. Look for the 
container with the name you specified earlier and verify it is running. 
It will be green if running and gray if not.

### Issue 1

When I run my image from 'Images' then go to 'Containers/Apps', instead of the 
container being green and running, it says it exited 0 seconds ago or smth.

## 5. Go Back to Terminal And Search Your Containers

```bash
# 5. Go back to terminal and search your Containers
docker ps -a
```

I guess 'ps' is like 'ls' but for Containers and Apps?

## 6, 7. Start and Login to Your Container

```bash
docker start your_container_name
docker exec -it your_container_name bash
```

### Issue 2

Here is the problem I have after `docker exec -it your_container_name bash`:  

    Error response from daemon: Container 7e00e329264755c54ecade7293066117f5822dc9136a1d18805c9e619ddb598d is not running

Those two commands cause an issue for me. I don't know if its because the 
container isn't running (see, [Issue 1](#issue-1)), or if I merely opened 
Docker Desktop and there is an actual daemon I need to install in order 
for additional Docker commands to execute in the terminal.

## 8-11: Container Configuration

```bash
ls  # Check you are in container
apt-get update
ping www.google.com
apt-get install iputils-ping
ping www.google.com
```

Now that we have executed our container, double check that we have correctly 
done so by using the `ls` command. You should see files pertaining to a base 
Linux directory.  

Always (probably) run `apt-get update` when first starting up your container 
to make sure your Linux image is up to date.  

We can check to see if we are able to ping certain addresses, but it is 
probably not installed yet in our base Linux distribution. If we are not able 
to ping out of the box, we can use the Linux package manager `apt` to install 
this package with the command `apt-get install iputils-ping`.  

## TO-DO:

Now that we are in Docker, there are a few things we need to set up. 

1. Text Editor
    * vim
    * probably don't bring nvim and the whole LSP over

2. Git integration (probably)

2. Compilers:
    * clang/g++

3. Debuggers:
    * lldb

4. c++ stl include's:
    * llvm
    * ggc@12

5. Memory Checker:
    * valgrind

6. Document sync with projects in macOS

7. `make`

8. Multiplexer
    * tmux

## Syncing With Files From Your Local System

Figure out how to mount a volume  



# Using Docker and Syncing Files

The next tutorial is taken from [Christian Lempa's](https://www.youtube.com/@christianlempa) 
how to use docker tutorial: <https://www.youtube.com/watch?v=y0GGQ2F2tvs>  

## Introduction

We will learn the basics of Containerization in Docker on Linux servers and how 
to easily migrate all your existing applications such as websites and databases 
into Docker containers.

## What is Docker? How Does it Work?

Docker is an open-source application that allows for containerization. 
Containerization means we can run applications isolated from each other and 
deploy them in packages. How is it different from virtualization? Both 
provide a layer of abstraction between the host and the applications. 
However, containers only run on the same type of operating system that is 
installed on the host (i.e. you can only run Windows containers on a Windows 
host, and Linux containers on a Linux host). Unlike virtual machines, container 
images don't contain a full operating system stack. Instead, they only include 
the containerized applications and all the necessary libraries and packages the 
developer have packaged inside of the image.  

Docker images are incredibly lightweight and start up much faster than virtual 
machines.

## Getting Started With Docker

[Docker Man Page](https://docs.docker.com/engine/install/)   
[Docker Desktop MacOS](https://www.docker.com/products/docker-desktop/)   
[Docker Hub - Container Database](https://hub.docker.com/)

After installing docker desktop, open Docker Desktop to begin running our 
Docker daemon and open your preffered terminal application. 

```bash
# Check to see if docker installed correctly
docker --version
# Run a test container to see if our docker daemon works
docker run hello-world

# (Optional) using the nginx web-server (non-persistent)
docker run -p 80:80 -d nginx
# Check all our currently running containers
docker ps
# Sample docker ps output
CONTAINER ID   IMAGE     COMMAND                  CREATED         STATUS        PORTS                               NAMES  
94988d766b03   ubuntu    "/bin/bash"              8 days ago      Up 2 days                                         compassionate_cray  
d6ed3d16f042   nginx     "/docker-entrypoint..."  9 seconds ago   Up 8 seconds  0.0.0.0:80->80/tcp, :::80->80/tcp   dazzling_goldwasser 
# Stopping a container
docker stop d6ed3e16f042
# Remove a container
docker rm d6ed3e16f042

# Using the nginx web-server (persistent)
# Go to browser url `localhost` to see if it installed correctly
# -v /absolute/path/to/local/project:/absolute/path/to/mount/location
# From video: docker run -p 80:80 -v nginx_data:/usr/share/nginx/html -d nginx
docker run -p 80:80 -v /Users/ickoxii/Coding/nginx/html:/usr/share/nginx/html -d nginx
# List all Docker Volumes (nginx_data should show up here)
docker volume ls
# Inspect your volume data
docker inspect nginx_data

# Now, even if we stop, remove, then redeploy our container,
# it will still have our data persistently
```

### Referring to Containers

Here is the output of a `docker ps` command:   

CONTAINER ID   IMAGE     COMMAND       CREATED      STATUS      PORTS     NAMES  
94988d766b03   ubuntu    "/bin/bash"   8 days ago   Up 2 days             compassionate_cray  

Each container is identified by a CONTAINER ID (94988d766b03) and a randomly 
assigned NAME (compassionate_cray).  

Containers can be referred to by either of identifiers when starting or 
stopping a container.

### The Web-Server Shenanigans

About `docker run -p 80:80 -d nginx` (non-persistent)  
Docker always isolates containers from each other, and it also isolates the 
network stack. So if we want access to a container, we always have to expose 
the correct network port. In our case, a simple web-server that does not use 
https uses port 80, so we expose port 80. The `-p 80:80` specifies the port 
to expose. `-d` allows us to run our container in the background so that we 
can interact with it after our `docker run` command finishes executing. If we 
do not run it in the background, it will exit almost immediately after the 
`docker run` command executes.  

Go to your browser and type `localhost` to see if it runs.

### Storing Images Persistently

Docker containers are immutable. This means that changes inside the container 
will not be reflected when it is stopped and restarted. In order to store data 
persistently in a container, we utilize **Docker Volumes**.  

Docker Volumes allows us to specify a specific data location or mount point 
inside our container. (Note: always check your container documentation to see 
what data should be stored persistently).  

If you want to change the configuration of a container, you always have to 
stop and redeploy that container. Containers are not made to run forever. They 
are immutable and meant to be deployed and redeployed very quickly.  

#### Specifying a Docker Volume

Check which volumes you have using `docker volume ls`.  

We can specify a volume to mount in our `docker run` command by using the `-v` 
flag, followed by our next argument.  

For me:   
`-v /Users/ickoxii/Coding/nginx/html:/usr/share/nginx/html`.  
The part before the colon is where the data is stored. The part after the colon 
is where the data will be mounted in your container. i.e., we take the location 
where our project is stored, and mount the data where our application expects 
to read it from.
