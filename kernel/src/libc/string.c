
void memcpy(void* dest, const void* src, int n)
{
    for (; n > 0; n--)
    {
        ((char*) dest)[n] = ((char*) src)[n];
    }
}