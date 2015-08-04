package com.example.burbsmobile.dbii_v12;

/**
 * Created by BurbsMobile on 4/22/2015.
 */

import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.Toast;


public class MyOnItemSelectedListener implements OnItemSelectedListener {

    @Override
    public void onItemSelected(AdapterView parent, View view, int pos, long id){
        Toast.makeText(parent.getContext(), "Select Table : " +
                parent.getItemAtPosition(pos).toString(), Toast.LENGTH_SHORT).show();
    }

    @Override
    public void  onNothingSelected(AdapterView parent){

    }
}
