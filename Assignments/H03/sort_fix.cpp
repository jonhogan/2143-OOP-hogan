// It would be better to use the built in 
// vector "sort". But ... oh well.
void Hand::Sort(){

    // Index "i" 
    for(int i = 0; i < Size(); i++)
    {
        // Index "j"
        // To correct the sorting issue, extended the control variable to Size()
        // instead of Size()-1 - Hogan
        for(int j = i; j < Size(); j++)
        {
            //Comparing cards at position i and j 
            // Changed from Cards[i]->rank < Cards[j]->rank - Hogan
            if(Cards[i]->rank > Cards[j]->rank)
            {
                cout<<"swapping"<<endl;

               
                // standard swap 
             Card *temp = Cards[i];
             Cards[i] = Cards[j];
             Cards[j] = temp;
            }
        }
    }
}
