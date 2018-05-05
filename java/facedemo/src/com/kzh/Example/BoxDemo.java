package com.kzh.Example;

import java.awt.FlowLayout;

import javax.swing.Box;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

import com.sun.org.apache.xml.internal.security.Init;

public class BoxDemo extends JFrame{
	Box BoxH;
	Box BoxVOne;
	Box BoxVTwo;
	public BoxDemo(){
		this.setLayout(new FlowLayout());
		init();
		this.setVisible(true);
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	void init(){
		BoxH = Box.createHorizontalBox();
		BoxVOne = Box.createVerticalBox();
		BoxVTwo = Box.createVerticalBox();
		BoxVOne.add(new JLabel("ÐÕÃû:"));
		BoxVOne.add(new JLabel("Ö°Òµ:"));
		BoxVTwo.add(new JTextField(10));
		BoxVTwo.add(new JTextField(10));
		BoxH.add(BoxVOne);
		BoxH.add(Box.createHorizontalStrut(10));
		BoxH.add(BoxVTwo);
		this.add(BoxH);
	}
	
}
