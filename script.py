import pandas as pd

# Wczytanie danych
df = pd.read_csv("czasy.csv")

# Zapis do Excela z wykresem
with pd.ExcelWriter("czasy.xlsx", engine="xlsxwriter") as writer:
    df.to_excel(writer, sheet_name="Dane", index=False)

    workbook = writer.book
    worksheet = writer.sheets["Dane"]
    chart = workbook.add_chart({"type": "line"})

    # Zakładamy, że dane są od A2 do B4
    # czyli kolumna A: kategorie (np. czasy startu), kolumna B: wartości (np. różnice czasu)
    num_rows = len(df)  # np. 3 jeśli masz dane od A2 do A4
    print(num_rows)
    chart.add_series({
        "categories": f"=Dane!A2:A{num_rows + 1}",  # A2 do A48
        "values":     f"=Dane!B2:B{num_rows + 1}",  # B2 do B4
        "name":       "quick_sort"
    })

    chart.add_series({
        "categories": f"=Dane!A2:A{num_rows + 1}",  # A2 do A4
        "values":     f"=Dane!C2:C{num_rows + 1}",  # B2 do B4
        "name":       "shell_sort"
    })

    chart.add_series({
        "categories": f"=Dane!A2:A{num_rows + 1}",  # A2 do A4
        "values":     f"=Dane!D2:D{num_rows + 1}",  # B2 do B4
        "name":       "heap_sort"
    })

    # chart.add_series({
    #     "categories": f"=Dane!A11:A13",  # A2 do A4
    #     "values":     f"=Dane!B11:B13",  # B2 do B4
    #     "name":       "quick_sort"
    # })

    # chart.add_series({
    #     "categories": f"=Dane!A14:A16",  # A2 do A4
    #     "values":     f"=Dane!B14:B16",  # B2 do B4
    #     "name":       "shell_sort"
    # })

    # chart.add_series({
    #     "categories": f"=Dane!A17:A19",  # A2 do A4
    #     "values":     f"=Dane!B17:B19",  # B2 do B4
    #     "name":       "heap_sort"
    # })

    worksheet.insert_chart("D2", chart)
