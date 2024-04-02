# Dockerize a Maven Projet

## Useful Commands - Quick Reference

1. Show all containers: `docker ps -a`
2. Delete all stopped containers: `docker rm $(docker ps -a -q)`
3. Remove all untagged images: `docker rmi $(docker images -f "dangling=true" -q)`

## Basic Container

<https://www.educative.io/answers/how-do-you-dockerize-a-maven-project>

1. Create a maven project

2. Create a `Dockerfile`

```docker
FROM openjdk:8
ADD target/my-maven-docker-project.jar /app/my-maven-docker-project.jar
WORKDIR /app
ENTRYPOINT ["java", "-jar", "my-maven-docker-project.jar"]
EXPOSE 8080
```

3. Run our docker image

```zsh
docker build -t my-docker-project-name
docker run -p 8080:8080 my-docker-project-name
```

4. Access `localhost:8080` from your browser

### Pros

* Simple Dockerfile

* Quick and easy

### Cons

* Does not support GUI

## GUI Docker Container for Swing App

### Research

* [\[yt\] Connect to GUI Apps on Linux Using XQuartz on Mac](https://www.youtube.com/watch?v=s6e3cqCISaE)
* [\[yt\] How to Set Up x11 Forwarding on your Mac](https://www.youtube.com/watch?v=-PCyR7pTlBc)
* [\[medium\] How to dockerize a Java GUI Application](https://learnwell.medium.com/how-to-dockerize-a-java-gui-application-bce560abf62a)
* [\[gh\] Jira Client inside docker container on mac/osx](https://github.com/pulkitsinghal/jira-client-inside-docker#steps)
* [\[gh\] x11 Forwarding on macOS and docker](https://gist.github.com/sorny/969fe55d85c9b0035b0109a31cbcb088)
* [\[gh\] x11 in docker on macos](https://gist.github.com/cschiewek/246a244ba23da8b9f0e7b11a68bf3285)
    * [\[docker\] How Docker Compose works](https://docs.docker.com/compose/compose-application-model/)
* [\[res\] Xquartz](https://www.xquartz.org/)
* [\[docker\] How to containerize](https://docs.docker.com/language/java/containerize/)

* I need a way to forward my java application through the docker container
  into an x11 display

* ***None of that shit above works for me tbh honest***

### Heres How to Actually Do That Shit

Host OS: macOS

1. Download [Xquartz](https://www.xquartz.org/) to host x11 forwarding on macOS

```zsh
brew install xquartz
```

2. Open `xquartz` and run the following command to start listening

```zsh
xhost $(ipconfig getifaddr en0)
```

3. Open Docker Desktop

4. Go back to your terminal (the one with the project) and make a `Dockerfile`

```docker
FROM ubuntu:22.04

# Install necessary libraries for x11 forwarding
RUN apt-get update && \
    apt-get install -y libxext6 libxrender1 libxtst6 openjdk-17-jdk

COPY target/lab7-0.0.1-SNAPSHOT.jar lab7-0.0.1-SNAPSHOT.jar

CMD java -jar lab7-0.0.1-SNAPSHOT.jar
```

5. Build and run your image

```zsh
docker build -t <imageName> .
docker run -it -e DISPLAY="$(getipconfig getifaddr en0)":0 <imageName>
```

## GUI Docker

* [Linux Webtop](https://docs.linuxserver.io/images/docker-webtop/)
* [WebSwing](https://www.webswing.org/en/)
* [WebSwing Demo](https://prototype.webswing.org/webswing-demo/)
