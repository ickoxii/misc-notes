# Running Linux on MacOS Through Docker Desktop

```bash
# Open Docker Desktop to have access to the daemon

# Pull the latest ubuntu image
docker pull ubuntu

# Display all of your images
docker image ls
REPOSITORY              TAG      IMAGE ID       CREATED       SIZE
ubuntu                  latest   e343402cadef   7 weeks ago   69.2 mb

# Run your image as a detached interactive tty container
docker run -dit --name my-ubuntu ubuntu

# Now lets run bash through our Linux container
docker exec -it my-ubuntu bash
root@56b77e7a7b67:/# 
```
