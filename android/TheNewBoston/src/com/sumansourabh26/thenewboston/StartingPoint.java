package com.sumansourabh26.thenewboston;

import android.R.integer;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class StartingPoint extends Activity {

	int counter ;
	Button addButton, subtractButton;
	TextView displayTextView;
	
	@Override	
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_starting_point);
		counter = 0;
		addButton = (Button) findViewById(R.id.addButton);
		subtractButton = (Button) findViewById(R.id.subtractButton);
		
		displayTextView = (TextView) findViewById(R.id.displaytextview);
		
		addButton.setOnClickListener(new View.OnClickListener() {
			public void onClick(View v) {
				counter++;
				displayTextView.setText("Your total is "+counter);
			}
		});
		subtractButton.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				counter--;
				displayTextView.setText("Your total is "+counter);
			}
		});
		
	}
}
