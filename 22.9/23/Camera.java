<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>org.example</groupId>
    <artifactId>project_22.9.23</artifactId>
    <version>1.0-SNAPSHOT</version>

    <properties>
        <maven.compiler.source>11</maven.compiler.source>
        <maven.compiler.target>11</maven.compiler.target>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
    </properties>

    <build>
        <defaultGoal>compile</defaultGoal>
    </build>

</project>

package com.javacv;

import javax.swing.JFrame;

import org.bytedeco.javacv.CanvasFrame;
import org.bytedeco.javacv.OpenCVFrameConverter;
import org.bytedeco.javacv.FrameGrabber.Exception;
import org.bytedeco.javacv.OpenCVFrameGrabber;

class Java{
    public static void main(String[] args) throws Exception, InterruptedException
    {

        OpenCVFrameGrabber grabber = new OpenCVFrameGrabber(0);
        grabber.start();  //开始获取摄像头

        CanvasFrame canvas = new CanvasFrame("前置摄像头");
        canvas.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        while(canvas.isDisplayable())
        {
            canvas.showImage(grabber.grab());
        }
        grabber.close();  //停止获取
    }
}
