package com.kzh.facetest;

import java.awt.Color;
import java.awt.Component;
import java.awt.GridLayout;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import com.sun.xml.internal.ws.org.objectweb.asm.Label;

public class PanelGridLayout extends JPanel{
	public PanelGridLayout() {
		// TODO Auto-generated constructor stub
		GridLayout gridLayout = new GridLayout(12,12); //Íø¸ñ²¼¾Ö
		setLayout(gridLayout);
		JLabel label[][] = new JLabel[12][12];
		for(int i=0;i<12;i++){
			for(int j=0;j<12;j++){
				label[i][j] = new JLabel();
				
				if((i+j)%2==0){
					label[i][j].setBackground(Color.black);
					label[i][j].setOpaque(true);
					label[i][j].setVisible(true);
				}
				else {
					label[i][j].setBackground(Color.white);
					label[i][j].setOpaque(true);
					label[i][j].setVisible(true);
				}
			}
		}
	}
}
