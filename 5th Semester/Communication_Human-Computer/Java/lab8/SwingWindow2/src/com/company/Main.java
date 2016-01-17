package com.company;

import javax.swing.*;
import java.awt.*;

public class Main extends javax.swing.JFrame {

    public Main() throws HeadlessException {
        JFrame frame = new JFrame("Screen IO utility");
        JFrame.setDefaultLookAndFeelDecorated(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel leftPanel = new JPanel(new GridLayout(2,1));
        leftPanel.setBorder(BorderFactory.createTitledBorder("Text IO Zone"));
        JTextArea source = new JTextArea();
        source.setBorder(BorderFactory.createTitledBorder("Source"));
        leftPanel.add(source);
        JTextArea output = new JTextArea();
        output.setBorder(BorderFactory.createTitledBorder("Output"));
        leftPanel.add(output);
        JPanel rightPanel = new JPanel(new GridLayout(5,1));
        rightPanel.setBorder(BorderFactory.createTitledBorder("Run Time"));
        rightPanel.add(new JButton("Runtime utility"));
        rightPanel.add(new JButton("Clear Source"));
        JButton help = new JButton("Help");
        help.setEnabled(false);
        rightPanel.add(help);
        rightPanel.add(new JButton("About"));
        rightPanel.add(new JButton("Exit and Save"));
        frame.setLayout(new GridLayout(1,2));
        frame.add(leftPanel);
        frame.add(rightPanel);
        frame.pack();

        frame.setSize(300, 300);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        Main frame = new Main();
    }
}
