import matplotlib.pyplot as plt
import pandas as pd

linkedin_data = pd.read_csv("C:\\Users\\Desktop\\Documents\\Programming\\ComputerScience\\Trabalhos\\Visualizacao_da_Informacao\\linkedindata.csv")

microsoft_gender_distribution = linkedin_data.loc[linkedin_data["c_name"] == "Microsoft"].pivot_table(columns = "gender", aggfunc = "size")

labels = ["Mulher", "Homem"]
values = microsoft_gender_distribution.values.tolist()

fig, ax = plt.subplots()

ax.set_title("Distribuição de gênero entre funcionários da Microsoft", fontweight = "bold")
ax.pie(values, labels = labels, autopct = "%1.1f%%", pctdistance = 0.85, startangle = 90, counterclock = False, colors = ["#DBFF72", "#32AAFF"])
ax.axis("equal")

center_circle = plt.Circle((0, 0), 0.7, fc="#FFFFFF")
fig = plt.gcf()
fig.gca().add_artist(center_circle)

plt.show()