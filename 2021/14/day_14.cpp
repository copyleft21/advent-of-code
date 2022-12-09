#include <algorithm>
#include <array>
#include <limits>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

extern const map<string, char> input0;
extern const map<string, char> input;

void print_result(const map<string, size_t>& counts, char last)
{
   map<char, size_t> final_counts;

   for (auto& item : counts)
   {
       final_counts[item.first[0]] += item.second;
   }
   final_counts[last]++;

   cout << endl;
   size_t min = numeric_limits<size_t>::max();
   size_t max = 0;
   for (auto& item : final_counts)
   {
       cout << item.first << ":" << item.second << endl;
       min = std::min(min, item.second);
       max = std::max(max, item.second);
   }

   cout << endl << max << "-" << min << "=" << max - min << endl;
}

void print(const map<string, size_t>& counts)
{
    for (const auto& it : counts)
      cout << it.first << ":" << it.second << endl;
}

void step(
    map<string, size_t>& counts,
    const map<string, pair<string, string>>& rules)
{
    map<string, size_t> tmp = counts;

    for (auto& item : tmp)
    {
        if (item.second)
        {
        const string& p = item.first;
        const pair<string, string>& rule = rules.at(p);
        size_t n = item.second;
        counts[p] -= n;
        counts[rule.first] += n;
        counts[rule.second] += n;
        // cout << endl;print(counts);
        }
    }
}

void process(
    const string& initial,
    const map<string, pair<string, string>>& rules,
    size_t steps=10)
{
    map<string, size_t> counts;
    
    for (auto& rule : rules)
    {
        counts[rule.first] = 0;
    }

    for (size_t i=0; i<initial.size()-1; ++i)
    {
        char pair[3]{};
        pair[0] = initial[i];
        pair[1] = initial[i+1];
        pair[2] = 0;
        counts[pair]++;
    }

    // print(counts);

    for (size_t i=0; i<steps; ++i) step(counts, rules);
    // cout << endl; print(counts);

    print_result(counts, initial.back());
}

void prepare(
    map<string, pair<string, string>>& rules,
    const map<string, char>& input)
{
   for(auto& rule: input)
   {
       string r1 = rule.first;
       string r2 = r1;
       r1[1] = rule.second;
       r2[0] = rule.second;
       rules[rule.first] = {r1, r2};
   }
}

int main()
{
    map<string, pair<string, string>> rules;

    //*
    prepare(rules, input);
    process("HBCHSNFFVOBNOFHFOBNO", rules, 40);
    return 0;
    //*/

    prepare(rules, input0);
    process("NNCB", rules);

    return 0;
}

const map<string, char> input0
{
  {"CH", 'B'},
  {"HH", 'N'},
  {"CB", 'H'},
  {"NH", 'C'},
  {"HB", 'C'},
  {"HC", 'B'},
  {"HN", 'C'},
  {"NN", 'C'},
  {"BH", 'H'},
  {"NC", 'B'},
  {"NB", 'B'},
  {"BN", 'B'},
  {"BB", 'N'},
  {"BC", 'B'},
  {"CC", 'N'},
  {"CN", 'C'}    
};

const map<string, char> input
{
  {"HF", 'O'},
  {"KF", 'F'},
  {"NK", 'F'},
  {"BN", 'O'},
  {"OH", 'H'},
  {"VC", 'F'},
  {"PK", 'B'},
  {"SO", 'B'},
  {"PP", 'H'},
  {"KO", 'F'},
  {"VN", 'S'},
  {"OS", 'B'},
  {"NP", 'C'},
  {"OV", 'C'},
  {"CS", 'P'},
  {"BH", 'P'},
  {"SS", 'P'},
  {"BB", 'H'},
  {"PH", 'V'},
  {"HN", 'F'},
  {"KV", 'H'},
  {"HC", 'B'},
  {"BC", 'P'},
  {"CK", 'P'},
  {"PS", 'O'},
  {"SH", 'N'},
  {"FH", 'N'},
  {"NN", 'P'},
  {"HS", 'O'},
  {"CB", 'F'},
  {"HH", 'F'},
  {"SB", 'P'},
  {"NB", 'F'},
  {"BO", 'V'},
  {"PN", 'H'},
  {"VP", 'B'},
  {"SC", 'C'},
  {"HB", 'H'},
  {"FP", 'O'},
  {"FC", 'H'},
  {"KP", 'B'},
  {"FB", 'B'},
  {"VK", 'F'},
  {"CV", 'P'},
  {"VF", 'V'},
  {"SP", 'K'},
  {"CC", 'K'},
  {"HV", 'P'},
  {"NC", 'N'},
  {"VH", 'K'},
  {"PF", 'P'},
  {"PB", 'S'},
  {"BF", 'K'},
  {"FF", 'C'},
  {"FV", 'V'},
  {"KS", 'H'},
  {"VB", 'F'},
  {"SV", 'F'},
  {"HO", 'B'},
  {"FN", 'C'},
  {"SN", 'F'},
  {"OB", 'N'},
  {"KN", 'P'},
  {"BV", 'H'},
  {"ON", 'N'},
  {"NF", 'S'},
  {"OF", 'P'},
  {"NV", 'S'},
  {"VS", 'C'},
  {"OO", 'C'},
  {"BP", 'H'},
  {"BK", 'N'},
  {"CP", 'N'},
  {"PC", 'K'},
  {"CN", 'H'},
  {"KB", 'B'},
  {"BS", 'P'},
  {"KK", 'P'},
  {"SF", 'V'},
  {"CO", 'V'},
  {"CH", 'P'},
  {"FO", 'B'},
  {"FS", 'F'},
  {"VO", 'H'},
  {"NS", 'F'},
  {"KC", 'H'},
  {"VV", 'K'},
  {"NO", 'P'},
  {"OK", 'F'},
  {"PO", 'V'},
  {"FK", 'H'},
  {"OP", 'H'},
  {"PV", 'N'},
  {"CF", 'P'},
  {"NH", 'K'},
  {"SK", 'O'},
  {"KH", 'P'},
  {"HP", 'V'},
  {"OC", 'V'},
  {"HK", 'F'}
};