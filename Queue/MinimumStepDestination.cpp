int minimum_distance(int sx, int sy, int dx, int dy) 
{
    if (dx < sx || dy < sy) {
        return -1;
    }
    return (dx - sx) + (dy - sy);
}