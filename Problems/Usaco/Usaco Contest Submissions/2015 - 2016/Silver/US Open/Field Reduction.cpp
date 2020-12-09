#include<bits/stdc++.h>
using namespace std;
struct point {
	int x, y;
	const bool operator==(point& b) const {
		return x == b.x and y == b.y;
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("reduce.in", "r", stdin); freopen("reduce.out", "w", stdout);
	int n;
	cin >> n;
	vector<point> pointsx;
	vector<point> pointsy;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pointsx.push_back({ x,y });
	}
	if (n <= 4) {
		cout << 0;
	}
	else {
		pointsy = pointsx;
		sort(pointsx.begin(), pointsx.end(), [&](const point& a, const point& b)
			{return a.x == b.x ? a.y < b.y : a.x < b.x; });
		sort(pointsy.begin(), pointsy.end(), [&](const point& a, const point& b)
			{return a.y == b.y ? a.x < b.x : a.y < b.y; });
		for (auto p : pointsx) {
			cout << p.x << ' ';
		}
		cout << '\n';
		for (auto p : pointsy) {
			cout << p.y << ' ';
		}
		cout << '\n';
		vector<point> removed;
		long long smallest_area = 1ll << 62;
		int added1 = 0, added2 = 0, added3 = 0, added4 = 0;
		int idx1 = 0, idx2 = n - 1, idx3 = 0, idx4 = n - 1;
		for (int min_x = 0; min_x <= 3; min_x++) {
			idx1 = 0, added1 = 0;
			int change12 = 0, change13 = 0, change14 = 0;
			if (removed.size() + min_x > 3) {
				break;
			}
			else {
				while (added1 != min_x) {
					bool exists = false;
					for (auto p : removed) {
						if (p == pointsx[idx1]) {
							exists = true;
							break;
						}
					}
					if (!exists) {
						added1++;
						removed.push_back(pointsx[idx1]);
					}
					idx1++;
				}
			}
			if (removed.size() == 3) {
				smallest_area = min(smallest_area,
					(long long)(pointsx[idx2].x - pointsx[idx1].x)
					* (pointsy[idx4].y - pointsy[idx3].y));
				cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
				for (int i = 0; i < min_x; i++) {
					removed.pop_back();
				}
				break;
			}
			for (int max_x = 0; max_x <= 3; max_x++) {
				int change21 = 0, change23 = 0, change24 = 0;
				idx2 = n - 1; added2 = 0;
				if (removed.size() + max_x > 3) {
					break;
				}
				else {
					while (added2 != max_x) {
						bool exists = false;
						for (auto p : removed) {
							if (p == pointsx[idx2]) {
								exists = true;
								break;
							}
						}
						if (!exists) {
							added2++;
							removed.push_back(pointsx[idx2]);
						}
						idx2--;
					}
				}
				if (removed.size() == 3) {
					smallest_area = min(smallest_area,
						(long long)(pointsx[idx2].x - pointsx[idx1].x)
						* (pointsy[idx4].y - pointsy[idx3].y));
					cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
					for (int i = 0; i < max_x; i++) {
						removed.pop_back();
					}
					idx2 = n - 1; added2 = 0;
					break;
				}
				for (int min_y = 0; min_y <= 3; min_y++) {
					int change31 = 0, change32 = 0, change34 = 0;
					idx3 = 0; added3 = 0;
					if (removed.size() + min_y > 3) {
						break;
					}
					else {
						while (added3 != min_y) {
							bool exists = false;
							for (auto p : removed) {
								if (p == pointsy[idx3]) {
									exists = true;
									break;
								}
							}
							if (!exists) {
								added3++;
								removed.push_back(pointsy[idx3]);
							}
							idx3++;
						}
					}
					if (removed.size() == 3) {
						smallest_area = min(smallest_area,
							(long long)(pointsx[idx2].x - pointsx[idx1].x)
							* (pointsy[idx4].y - pointsy[idx3].y));
						cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
						for (int i = 0; i < min_y; i++) {
							removed.pop_back();
						}
						idx3 = 0; added3 = 0;
						break;
					}
					for (int max_y = 0; max_y <= 3; max_y++) {
						int change41 = 0, change42 = 0, change43 = 0;
						idx4 = n - 1; added4 = 0;
						if (removed.size() + max_y > 3) {
							break;
						}
						else {
							while (added4 != max_y) {
								bool exists = false;
								for (auto p : removed) {
									if (p == pointsy[idx4]) {
										exists = true;
										break;
									}
								}
								if (!exists) {
									added4++;
									removed.push_back(pointsy[idx4]);
								}#include<bits/stdc++.h>
									using namespace std;
								struct point {
									int x, y;
									const bool operator==(point& b) const {
										return x == b.x and y == b.y;
									}
								};
								int main() {
									ios_base::sync_with_stdio(0); cin.tie(0);
									//freopen("reduce.in", "r", stdin); freopen("reduce.out", "w", stdout);
									int n;
									cin >> n;
									vector<point> pointsx;
									vector<point> pointsy;
									for (int i = 0; i < n; i++) {
										int x, y;
										cin >> x >> y;
										pointsx.push_back({ x,y });
									}
									if (n <= 4) {
										cout << 0;
									}
									else {
										pointsy = pointsx;
										sort(pointsx.begin(), pointsx.end(), [&](const point& a, const point& b)
											{return a.x == b.x ? a.y < b.y : a.x < b.x; });
										sort(pointsy.begin(), pointsy.end(), [&](const point& a, const point& b)
											{return a.y == b.y ? a.x < b.x : a.y < b.y; });
										for (auto p : pointsx) {
											cout << p.x << ' ';
										}
										cout << '\n';
										for (auto p : pointsy) {
											cout << p.y << ' ';
										}
										cout << '\n';
										vector<point> removed;
										long long smallest_area = 1ll << 62;
										int added1 = 0, added2 = 0, added3 = 0, added4 = 0;
										int idx1 = 0, idx2 = n - 1, idx3 = 0, idx4 = n - 1;
										for (int min_x = 0; min_x <= 3; min_x++) {
											idx1 = 0, added1 = 0;
											int change12 = 0, change13 = 0, change14 = 0;
											if (removed.size() + min_x > 3) {
												break;
											}
											else {
												while (added1 != min_x) {
													bool exists = false;
													for (auto p : removed) {
														if (p == pointsx[idx1]) {
															exists = true;
															break;
														}
													}
													if (!exists) {
														added1++;
														removed.push_back(pointsx[idx1]);
													}
													idx1++;
												}
											}
											if (removed.size() == 3) {
												smallest_area = min(smallest_area,
													(long long)(pointsx[idx2].x - pointsx[idx1].x)
													* (pointsy[idx4].y - pointsy[idx3].y));
												cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
												for (int i = 0; i < min_x; i++) {
													removed.pop_back();
												}
												break;
											}
											for (int max_x = 0; max_x <= 3; max_x++) {
												int change21 = 0, change23 = 0, change24 = 0;
												idx2 = n - 1; added2 = 0;
												if (removed.size() + max_x > 3) {
													break;
												}
												else {
													while (added2 != max_x) {
														bool exists = false;
														for (auto p : removed) {
															if (p == pointsx[idx2]) {
																exists = true;
																break;
															}
														}
														if (!exists) {
															added2++;
															removed.push_back(pointsx[idx2]);
														}
														idx2--;
													}
												}
												if (removed.size() == 3) {
													smallest_area = min(smallest_area,
														(long long)(pointsx[idx2].x - pointsx[idx1].x)
														* (pointsy[idx4].y - pointsy[idx3].y));
													cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
													for (int i = 0; i < max_x; i++) {
														removed.pop_back();
													}
													idx2 = n - 1; added2 = 0;
													break;
												}
												for (int min_y = 0; min_y <= 3; min_y++) {
													int change31 = 0, change32 = 0, change34 = 0;
													idx3 = 0; added3 = 0;
													if (removed.size() + min_y > 3) {
														break;
													}
													else {
														while (added3 != min_y) {
															bool exists = false;
															for (auto p : removed) {
																if (p == pointsy[idx3]) {
																	exists = true;
																	break;
																}
															}
															if (!exists) {
																added3++;
																removed.push_back(pointsy[idx3]);
															}
															idx3++;
														}
													}
													if (removed.size() == 3) {
														smallest_area = min(smallest_area,
															(long long)(pointsx[idx2].x - pointsx[idx1].x)
															* (pointsy[idx4].y - pointsy[idx3].y));
														cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
														for (int i = 0; i < min_y; i++) {
															removed.pop_back();
														}
														idx3 = 0; added3 = 0;
														break;
													}
													for (int max_y = 0; max_y <= 3; max_y++) {
														int change41 = 0, change42 = 0, change43 = 0;
														idx4 = n - 1; added4 = 0;
														if (removed.size() + max_y > 3) {
															break;
														}
														else {
															while (added4 != max_y) {
																bool exists = false;
																for (auto p : removed) {
																	if (p == pointsy[idx4]) {
																		exists = true;
																		break;
																	}
																}
																if (!exists) {
																	added4++;
																	removed.push_back(pointsy[idx4]);
																}
																idx4--;
															}
														}
														if (removed.size() == 3) {
															smallest_area = min(smallest_area,
																(long long)(pointsx[idx2].x - pointsx[idx1].x)
																* (pointsy[idx4].y - pointsy[idx3].y));
															cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
															for (int i = 0; i < max_y; i++) {
																removed.pop_back();
															}
															idx4 = n - 1; added4 = 0;
															break;
														}
													}
												}
											}
										}
										cout << smallest_area;
									}
								}
								idx4--;
							}
						}
						if (removed.size() == 3) {
							smallest_area = min(smallest_area,
								(long long)(pointsx[idx2].x - pointsx[idx1].x)
								* (pointsy[idx4].y - pointsy[idx3].y));
							cout << idx2 << ' ' << idx1 << ' ' << idx4 << ' ' << idx3 << '\n';
							for (int i = 0; i < max_y; i++) {
								removed.pop_back();
							}
							idx4 = n - 1; added4 = 0;
							break;
						}
					}
				}
			}
		}
		cout << smallest_area;
	}
}