#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

/*
unsigned int SDBMHash(string str, unsigned int num_buckets) {
    unsigned int hash = 0;

    for (unsigned int i = 0; i < str.length(); i++) {
        hash = (str[i] + (hash << 6) + (hash << 16) - hash) ;
    }

    return hash%num_buckets;
}
    */


int SDBMHash(const string& name, unsigned int num_buckets) {
    unsigned long sum = 0;
    for (char c : name) sum += (unsigned char)c;
    return (int)(sum % num_buckets);
}