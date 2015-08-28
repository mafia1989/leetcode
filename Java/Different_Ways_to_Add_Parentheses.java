// Different Ways to Add Parentheses Total Accepted: 5695 Total Submissions: 21883 My Submissions Question Solution 
// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
// The valid operators are +, - and *.


// Example 1
// Input: "2-1-1".

// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]


// Example 2
// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]


//My Solution

public class Solution {
    public List<Integer> diffWaysToCompute(String input) 
    {
        List<Integer> list = new ArrayList<Integer>();
        
        if(input == null || input.length() == 0)
           return list;
           
        for(int i = 0; i< input.length();i++)
        {
            char c = input.charAt(i);
            if(c == '+' || c == '-' || c == '*')
            {
                String left = input.substring(0,i);
                String right = input.substring(i+1,input.length());
                
                List<Integer> leftList = diffWaysToCompute(left);
                List<Integer> rightList = diffWaysToCompute(right);
                
                for(Integer l:leftList)
                   for(Integer r:rightList)
                   {
                       if(c == '+')
                          list.add(l+r);
                       if(c == '-')
                          list.add(l-r);
                       if(c == '*')
                          list.add(l*r);
                   }
            }
        }
        
        if(list.size() == 0)
           list.add(Integer.valueOf(input));
           
        return list;
        
    }
}

