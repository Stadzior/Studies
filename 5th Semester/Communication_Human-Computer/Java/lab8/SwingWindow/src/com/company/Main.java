package com.company;

import javax.swing.*;
import java.awt.*;

public class Main extends javax.swing.JFrame {

    public Main() throws HeadlessException {
        JFrame frame = new JFrame("Screen IO utility");
        JFrame.setDefaultLookAndFeelDecorated(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JTextArea workArea = new JTextArea(1,20);
        workArea.setBorder(BorderFactory.createTitledBorder("Work Area"));
        JPanel rightPanel = new JPanel(new GridLayout(7,1));
        rightPanel.setBorder(BorderFactory.createTitledBorder("Run Time"));
        rightPanel.add(new JButton("Insert file"));
        rightPanel.add(new JButton("Clear text"));
        JButton runUtility = new JButton("Run utility");
        runUtility.setEnabled(false);
        rightPanel.add(runUtility);
        rightPanel.add(new JButton("Save file"));
        rightPanel.add(new JButton("Help"));
        rightPanel.add(new JButton("About"));
        rightPanel.add(new JButton("Exit"));
        frame.setLayout(new BorderLayout());
        frame.add(workArea,BorderLayout.WEST);
        frame.add(rightPanel,BorderLayout.EAST);
        frame.pack();

        frame.setSize(400, 300);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        Main frame = new Main();
    }
}
