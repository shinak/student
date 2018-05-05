package com.kzh.facetest;

import java.awt.BorderLayout;
import java.awt.Panel;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

public class showLayout extends JFrame{
	PanelGridLayout panelGridLayout;
	PanelNullLayout panelNullLayout;
	JTabbedPane pane;
	public showLayout() {
		// TODO Auto-generated constructor stub
		panelGridLayout = new PanelGridLayout();
		panelNullLayout = new PanelNullLayout();
		pane = new JTabbedPane();
		pane.add("网格布局的面板", panelGridLayout);
		pane.add("空布局的面板",panelNullLayout);
		this.add(pane,BorderLayout.CENTER);
		this.add(new JButton("窗体是BorderLayout布局"),BorderLayout.NORTH);
		this.add(new JButton("南"),BorderLayout.SOUTH);
		this.add(new JButton("西"),BorderLayout.WEST);
		this.add(new JButton("东"),BorderLayout.EAST);
		this.setBounds(10, 10, 570, 390);
		this.setVisible(true);
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		validate();
	}
}
