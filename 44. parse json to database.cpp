/*
class JSONValue{
public:
	string getAsString();
	int getAsInt();
	unordered_map<string, JSONValue> getAsMap();
	...	
};

class Row{
	string TableName;
	unordered_map<string, string> map;	
};
*/

class Config{
public:
	string getValue(string key, JSONValue value){
		if (key == "type" || key == "name" || key == "date") return value.getAsString();
		if (key == "player_id" || key == "session_id") return to_string(value.getAsInt());
	}
};

class Solution{
public:
	vector<Row> parseJsonToDB(vector<JSONValue> events, Config c){
		vector<Row> DB;
		for (auto event : events){
			Row newRow = *(new Row());
			unordered_map<string, JSONValue> eventData = event.getAsMap();
			newRow.TableName = eventData["type"].getAsString();
			unordered_map<string, JSONValue> dataMap = eventData["data"].getAsMap();
			for (auto i : dataMap){
				newRow.map[i.first] = c.getValue(i.first, i.second);
			}
			DB.push_back(newRow);
		}
		return DB;
	}
};

void main(){
	Config c();
	Solution s;
	s.parseJsonToDB(events, c);
}