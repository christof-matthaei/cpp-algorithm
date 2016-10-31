template<typename Iterator>
struct Range
{
    typedef iterator_traits< Iterator >::iterator_category	iterator_category;
    typedef iterator_traits< Iterator >::value_type 		value_type;
    typedef iterator_traits< Iterator >::difference_type 	difference_type;
    typedef iterator_traits< Iterator >::reference 			reference;
    typedef iterator_traits< Iterator >::pointer 			pointer;
    
    template<class Container>
    Range(Container const& c):
        first_{std::begin(c)}, last_{std::end(c)}
    {}
    
    Range(Iterator begin, Iterator end):
        first_{begin}, last_{end}
    {}
    
    
    Iterator begin() const
    {
        return first_;   
    }
    
    Iterator end() const
    {
        return last_;   
    }
    
    std::size_t size() const
    {
        return std::distance(first_, last_);    
    }
    
private:
    Iterator first_;
    Iterator last_;
};

template<typename Iterator>
Range<Iterator> make_range(Iterator&& begin, Iterator&& last)
{
    return Range<Iterator>{
        std::forward<Iterator>(begin),
        std::forward<Iterator>(last)};
}