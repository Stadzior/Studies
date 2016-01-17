package com.company;

import javax.swing.*;
import java.awt.*;

public class Main extends javax.swing.JFrame {

    public Main() throws HeadlessException {
        JFrame frame = new JFrame("Screen IO utility");
        JFrame.setDefaultLookAndFeelDecorated(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel leftPanel = new JPanel(new GridLayout(8,3));
        leftPanel.setBorder(BorderFactory.createTitledBorder("Text IO zone"));
        leftPanel.add(new JLabel("Source"));
        leftPanel.add(new JTextField());
        leftPanel.add(new JButton("Browse..."));
        leftPanel.add(new JLabel("Output"));
        leftPanel.add(new JTextField());
        leftPanel.add(new JButton("Browse..."));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        leftPanel.add(new JLabel(""));
        JPanel rightPanel = new JPanel(new GridLayout(4,1));
        rightPanel.setBorder(BorderFactory.createTitledBorder("Run Time options"));
        JButton runTheUtility = new JButton("Run the utility");
        runTheUtility.setEnabled(false);
        rightPanel.add(runTheUtility);
        rightPanel.add(new JButton("Help"));
        rightPanel.add(new JButton("About"));
        rightPanel.add(new JButton("Exit and save"));
        frame.setLayout(new BorderLayout());
        frame.add(leftPanel,BorderLayout.WEST);
        frame.add(rightPanel,BorderLayout.EAST);
        frame.pack();

        frame.setSize(400, 300);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        Main frame = new Main();
    }
}
