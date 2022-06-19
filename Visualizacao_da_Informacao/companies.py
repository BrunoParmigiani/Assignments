import matplotlib.pyplot as plt
import pandas as pd

linkedin_data = pd.read_csv("C:\\Users\\Desktop\\Documents\\Programming\\ComputerScience\\Trabalhos\\Visualizacao_da_Informacao\\linkedindata.csv")

companies = linkedin_data.pivot_table(columns = ["c_name"], aggfunc = "size").sort_values(ascending = False).iloc[:10]

labels = companies.index.tolist()
values = companies.values.tolist()

fig, ax = plt.subplots()

ax.set_title("As 10 empresas com o maior número de funcionários", fontweight = "bold")
ax.set_xlabel("Funcionários", fontweight = "bold")
ax.set_ylabel("Empresas", fontweight = "bold")
ax.invert_yaxis()

companie_value = ax.barh(labels, values, color = "#8CFF99", edgecolor = "#009911")
ax.bar_label(companie_value, padding = 5)

plt.show()