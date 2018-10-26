time_t to_time_t( boost::posix_time::ptime t )
{
    using namespace boost::posix_time;
    ptime epoch( boost::gregorian::date( 1970, 1, 1 ) );
    time_duration::sec_type x = ( t - epoch ).total_seconds();

    // ... check overflow here ...

    return time_t( x );
}
