# Learn Maven, the Project Management and Comprehension Tool

<https://maven.apache.org/>  

## Installation

MacOS: <https://www.digitalocean.com/community/tutorials/install-maven-mac-os>  
Windows: <https://phoenixnap.com/kb/install-maven-windows>  

## Example Repositories

<https://github.com/mkyong/maven-examples>

## Pom Files

1. Basic pom file
    * <https://mkyong.com/maven/how-to-create-a-java-project-with-maven/>
    * [basic-pom.xml](./basic-pom.xml)
2. Multi-module pom file
    * <https://mkyong.com/maven/maven-how-to-create-a-multi-module-project/>

## Using Maven

1. Create a Project from Maven Template  
```zsh
mvn archetype:generate
    -DgroupId={project-packaging}
    -DartifactId={project-name}
    -DarchetypeArtifactId={maven-template}
    -DinteractiveMode=false
```
2. Directory Layout
    * source code: `/src/main/java`
    * unit test code: `/src/test/java`
3. POM file
```xml
<!-- Base POM.xml file -->
<project xmlns="http://maven.apache.org/POM/4.0.0" 
	xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 
		 http://maven.apache.org/maven-v4_0_0.xsd">
    <modelVersion>4.0.0</modelVersion>
    <groupId>com.mkyong.hashing</groupId>
    <artifactId>java-project3</artifactId>
    <packaging>jar</packaging>
    <version>1.0-SNAPSHOT</version>
    <name>java-project</name>
    <url>http://maven.apache.org</url>
    <dependencies>
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>3.8.1</version>
            <scope>test</scope>
        </dependency>
    </dependencies>
</project>
```
4. Update POM
    1. Specify JDK version
    2. Update jUnit to 4.12
    3. Add any project dependencies
    4. Use `maven-shade-plugin` to group everything into a single jar file
    5. Specify main-class for the `maven-shade-plugin`
5. Build and run
```zsh
# Build
mvn package
# or repackage if needed
mvn clean package

# Run
java -jar target/java-project-1.0-SNAPSHOT.jar <cli arguments, if any>
```


## Misc

* No class in `src/test/java` is accessible to any class in `src/main/java`, BUT
* Any class in `src/main/java` **is** accessible to `src/test/java`
