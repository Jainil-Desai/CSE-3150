#include "cosine_distance.h"

using namespace std;

double dist_cos(const vector<double>& first_, const vector<double>& second_) {
    double product_dot = 0.0, frst = 0.0, scnd = 0.0;
    for (int i = 0; i < first_.size(); i++) {
        product_dot += first_[i] * second_[i];
        frst += first_[i] * first_[i];
        scnd += second_[i] * second_[i];
    }
    double sq_mult = (sqrt(frst) * sqrt(scnd));
    
    if (sq_mult == 0.0) {
        return 0.0; 
    }
    
    return product_dot / sq_mult;
}


vector<vector<double>> accessing_file(string txt_file) {
    vector<vector<double>> pairs_vect;
    ifstream open_file(txt_file);
    string s1;
    if (!open_file) {
        cerr << "Invalid file - could not open" << txt_file << "\n";
        exit(1);
    }
    while (getline(open_file, s1)) {
        double each;
        istringstream fl(s1);
        vector<double> cur_pr;

        while (fl >> each) {
            cur_pr.push_back(each);
        }
        pairs_vect.push_back(cur_pr);
    }
    return pairs_vect;
}

vector<pair<pair<int, int>, double>> distance_calculation(const vector<vector<double>>& pairs) {
    vector<pair<pair<int, int>, double>> cosine_dist;
    for (int i = 0; i < pairs.size(); i++) {
        for (int j = i + 1; j < pairs.size(); j++) {
            double cur_dist = dist_cos(pairs[i], pairs[j]);
            cosine_dist.push_back(make_pair(make_pair(i + 1, j + 1), cur_dist));
        }
    }
    return cosine_dist;
}

vector<pair<pair<int, int>, double>> sorting_function(const vector<pair<pair<int, int>, double>>& curr_dist) {
    vector<pair<pair<int, int>, double>> dist_ = curr_dist;
    sort(dist_.begin(), dist_.end(), [](auto& left, auto& right) {
        return left.second > right.second;
    });
    return dist_;
}

void output_pairs(const vector<pair<pair<int, int>, double>>& curr_pr) {
    for (const auto& i : curr_pr) {
        cout << "(" << i.first.first << "," << i.first.second << ") ";
    }
    cout << endl;
}