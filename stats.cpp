//Name : Matheus Figueroa 

#include "stats.h"
#include <cassert>
namespace main_savitch_2C
{

	statistician::statistician()
	{
		//CONSTRUCTOR: As soon as a statistician object is made, the length and sum are set to 0 by the use of the reset function
		reset();	
    
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void statistician::next(double r)
	{
		//PUBLIC MODIFIER : MEMBER FUNCTION
		//As new numbers are entered, the length increases incrementally 
    		m_len++;
		//The sum is initially set to 0, as more numbers are passed, the sum is added to the new number
    		m_sum += r;

		//This is the inital case. If one number is passed and then the table is printed, the minimum will be a garbage value. Therefore, if only one numberis passed, both minimum and maximum aris r
    		if(length() == 1)
    		{
    		    m_min = m_max = r;
    		}
		//The next case when more numbers are passed in, the maximum function is called and compared to the new r values being brought in. If the maximum value is still greater, the r value willbe compared to the minimum 
    		else 
    		{
        		if(r > maximum())
            		m_max = r;
        		else if(r < minimum())
            		m_min = r;

    		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////

	void statistician::reset() 
	{
		//PUBLIC MODIFIER : MEMBER FUNCTION
		//Initializes length and sum to 0
    		m_len = 0;
    		m_sum = 0;
	}

////////////////////////////////////////////////////////////////////////////////////////////////

	int statistician::length() const 
	{
		//CONSTANT MEMBER FUNCTION
		//read length
    		return m_len;
	}

////////////////////////////////////////////////////////////////////////////////////////////////

	double statistician::mean() const
	{
		//CONSTANT MEMBER FUNCTION
		//Precondition : make sure the length is greater than 0, otherwise, end the program with an error message
    		assert(length() > 0);
		//return the mean by dividing the sum by length 
    		return (m_sum / m_len);
	}

///////////////////////////////////////////////////////////////////////////////////////////////

	double statistician::maximum() const
	{
		//CONSTANT MEMBER FUNCTION
		//Precondition : make sure the length is greater than 0, otherwise, end the program with an error message
    		assert(length() > 0);
		//return maximum
    		return m_max;
	}

///////////////////////////////////////////////////////////////////////////////////////////////

	double statistician::minimum() const
	{
		//CONSTANT MEMBER FUNCTION
		//Precondition : make sure the length is greater than 0, otherwise, end the program with an error message
    		assert(length() > 0);
		//return the minimum
    		return m_min;
	}

//////////////////////////////////////////////////////////////////////////////////////////////

	double statistician::sum() const
	{
		//CONSTANT MEMBER FUNCTION
		//read the sum
    		return m_sum;
	}

///////////////////////////////////////////////////////////////////////////////////////////////

	bool operator ==(const statistician& s1, const statistician& s2)
	{
		//If s1 and s2 have zero length, return true
    		if(s2.length() == 0 && s1.length() == 0)
		{	
        		return true;
		}
		//If s1 and s2 have the same length, mean, sum, minimum, and maximum
    		else if (s2.length() == s1.length() && s2.sum() == s1.sum() && s2.minimum() == s1.minimum() && s2.maximum() == s1.maximum() && s2.mean() == s1.mean()) 
		{
                	return true;
		}
		//If these conditions are not met, return false
    		else
		{
        		return false;
    		}
	}

//////////////////////////////////////////////////////////////////////////////////////////////

	statistician operator +(const statistician& s1, const statistician& s2)
	{
		// s3 object is made 
    		statistician s3;
		//if the + operator is called and there have been no numbers passed into it, the value of s3 is returned which will be 0 as per the constructor
    		if(s1.length()==0 && s2.length()==0)
        		return s3;
		//if the length of s1 is 0, then the only value to add is s2, therefore, s3 holds s2 values
   		else if(s1.length() == 0)
        		return s2;
		//if the length of s2 is 0, then the only value to add is s1, therefore, s3 holds s1 values
    		else if(s2.length() == 0)
        		return s1;
		//This is the ideal case to add two values from the s1 and s2 table
    		else {
        		s3.m_len = s1.length() + s2.length();
        		s3.m_sum = s1.sum() + s2.sum();
			//an inline conditional read: if s1 max is less than s2 max, then s3 max = s2 max, else s3 max = s1 max
        		s3.m_max = (s1.maximum() <= s2.maximum()) ? s2.m_max : s1.m_max;
			//similar inline conditional as above, this time, for the minimum
        		s3.m_min = (s1.minimum() >= s2.minimum()) ? s2.m_min : s1.m_min;
    			}
	//return the new information for s3	
    	return s3;
	}

/////////////////////////////////////////////////////////////////////////////////////////////

	statistician operator *(double scale, const statistician& s)
	{
    		if(s.length() == 0)
		{ 
			//if no values were entered for statistician s1, return s
        		return s;
    		}
		
		//sc is the new object that will be scaled by a constant
    		statistician sc;
		//Statistician s3's length is now s1's length 
    		sc.m_len = s.length();
		//Statistician s3's sum is now scaled by a factor of the constant entered by the user
    		sc.m_sum = s.sum() * scale;

    		if(scale >= 0) 
		{
			//First case when the entered scaled us greater than zero, we can go ahead and multiply s1's minimum and maximum by that scale. This are the new values for s3
        		sc.m_max = s.maximum()*scale;
        		sc.m_min = s.minimum()*scale;
    		}
    		else 
		{
			//Next case, if the scale is smaller than zero, (negative), the max is the scaled result of the minimum and the new minimum is the scaled result of the max
        		sc.m_max = s.minimum()*scale;
        		sc.m_min = s.maximum()*scale;
    		}
    		return sc;
	}
}
