package com.kzh.example97;

public class Example9_7 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		WindowActionEvent win = new WindowActionEvent();
		PoliceListen policeListen = new PoliceListen();
		win.setMyCommandListener(policeListen);
		win.setBounds(100, 100, 460, 360);
		win.setTitle("deal of ActionEvent");
	}

}
