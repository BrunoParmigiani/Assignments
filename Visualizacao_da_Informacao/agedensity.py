import plotly.express as px
import pandas as pd

linkedin_data = pd.read_csv("C:\\Users\\Desktop\\Documents\\Programming\\ComputerScience\\Trabalhos\\Visualizacao_da_Informacao\\linkedindata.csv")

microsoft = linkedin_data.loc[linkedin_data["c_name"] == "Microsoft"]

males = microsoft.loc[microsoft["gender"] == "Male"]
male_age_distribution = males.loc[males["age"] > 17].pivot_table(columns = "age", aggfunc = "size")

females = microsoft.loc[microsoft["gender"] == "Female"]
female_age_distribution = females[females["age"] > 17].pivot_table(columns = "age", aggfunc = "size")

genders = [
    *["Homem" for i in male_age_distribution],
    *["Mulher" for i in female_age_distribution]
]

age_labels = [
    *male_age_distribution.index.tolist(),
    *female_age_distribution.index.tolist()
]

age_values = [
    *male_age_distribution.values.tolist(),
    *female_age_distribution.values.tolist()
]

df = pd.DataFrame(dict(genders = genders, age_labels = age_labels, age_values = age_values))

fig = px.treemap(df, path = [genders, age_labels], values = age_values)

fig.update_layout(
    title = dict(
        text = "<b>Densidade etária entre funcionários da Microsoft (18 anos e acima)</b>",
        font_color = "black",
        font_size = 24,
        x = 0.5
    )
)

fig.show()