# Configuring an Ubuntu VM on Docker

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
