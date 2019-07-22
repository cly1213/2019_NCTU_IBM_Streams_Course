package com.ibm.nctu;

import com.ibm.streams.operator.types.RString;

import com.ibm.streams.operator.OperatorContext;

import java.text.*;
import java.util.*;

public  class AddTime extends AbstractAddTime {


    /**
    ** Initialize the operator
    */
    @Override
    public void initialize(OperatorContext context) throws Exception {
        super.initialize(context);
        // TODO Auto-generated method stub
    }

    /**
    ** process method for port 0.
    */
    @Override
    protected void process0(IPort0 tuple) throws Exception {
        // TODO Auto-generated method stub
    	
    	DateFormat  df = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
    	
    	Date date = new Date();
    	RString currentDateTimeStr = new RString(df.format( date));
    	
    	OPort0 outputTuple = getOutput0().newTuple();
    	outputTuple.set_symbol (tuple.get_symbol());
    	outputTuple.set_price(tuple.get_price());
    	outputTuple.set_quantity (tuple.get_quantity());
    	outputTuple.set_tradetype (tuple.get_tradetype());
    	outputTuple.set_datetime (currentDateTimeStr);
    	submit0(outputTuple);

    }
}
