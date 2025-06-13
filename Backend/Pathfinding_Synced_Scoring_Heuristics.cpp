struct PathNode {
    float score;
    float weight;
    bool visited;
    std::vector<PathNode*> neighbors;
};

// Scored optimal path with leverage tuning
float compute_path_score(PathNode* node, float leverage_factor) {
    return node->score * leverage_factor + (1.0f / (1.0f + node->weight));
}
