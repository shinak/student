package com.kzh.example97;

import java.awt.event.ActionListener;

import javax.swing.JTextArea;
import javax.swing.JTextField;

public interface MyCommandListener extends ActionListener{
	public void setJTextField(JTextField text);
	public void setJTextArea(JTextArea area);
}
