#pragma once

template<typename RangeIn, typename RangeOut>
auto copy(RangeIn const& in, RangeOut& out)
{
    assert(in.size() <= out.size());
    
    auto out_f = std::begin(out);
    auto out_l = std::copy(std::begin(in), std::end(in), out_f);
    return make_range(out_f, out_l);
}

//-----------------------------------------------------------------------------

template<typename RangeIn, typename RangeOut, typename MemType>
auto copy(RangeIn const& in, RangeOut& out, MemType&& m)
{
    assert(in.size() <= out.size());
    
    auto pred = std::mem_fn(std::forward<MemType>(m));
    auto out_f = std::begin(out);
    auto out_l = std::begin(out);
    for(auto const& i : in)
    {
        *out_l = pred(i);
        ++out_l;
    }

    return make_range(out_f, out_l);
}


//-----------------------------------------------------------------------------
