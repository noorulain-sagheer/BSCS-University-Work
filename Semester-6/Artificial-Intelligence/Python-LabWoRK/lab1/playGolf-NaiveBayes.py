import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.naive_bayes import GaussianNB
# Load CSV
data = pd.read_csv(&quot;/content/PlayGolf.csv&quot;)
# Clean column names
data.columns = data.columns.str.strip()
# Encoders
le_outlook = LabelEncoder()
le_temp = LabelEncoder()
le_humidity = LabelEncoder()
le_windy = LabelEncoder()
le_play = LabelEncoder()
# Encode columns
data[&#39;Outlook&#39;] = le_outlook.fit_transform(data[&#39;Outlook&#39;])
data[&#39;Temperature&#39;] = le_temp.fit_transform(data[&#39;Temperature&#39;])
data[&#39;Humidity&#39;] = le_humidity.fit_transform(data[&#39;Humidity&#39;])
data[&#39;Windy&#39;] = le_windy.fit_transform(data[&#39;Windy&#39;])
data[&#39;PlayGolf&#39;] = le_play.fit_transform(data[&#39;PlayGolf&#39;])
# Features and target
X = data[[&#39;Outlook&#39;, &#39;Temperature&#39;, &#39;Humidity&#39;, &#39;Windy&#39;]]
y = data[&#39;PlayGolf&#39;]
# Train model
model = GaussianNB()
model.fit(X, y)
# Test case: Sunny, Cool, High, Strong
test = [[
    le_outlook.transform([&#39;Sunny&#39;])[0],
    le_temp.transform([&#39;Cool&#39;])[0],
    le_humidity.transform([&#39;High&#39;])[0],
    le_windy.transform([&#39;Strong&#39;])[0]
]]
prediction = model.predict(test)
print(&quot;Play Golf:&quot;, &quot;Yes&quot; if prediction[0] == 1 else &quot;No&quot;)
