package com.kzh.example96;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ReaderListen implements ActionListener {

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		String string = arg0.getActionCommand();
		System.out.println(string + ":" + string.length());
	}

}
