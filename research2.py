import re

def extract_alter_operations(sql_string):
    # Regular expression pattern to match ALTER TABLE statements with various operations
        alter_pattern = re.compile(r'\bALTER\s+TABLE\s+(\w+)\s+(ADD\s+(\w+\s+\w+\([^)]+\)(?:,\s*)?)|MODIFY\s+(\w+\s+\w+\([^)]+\))|RENAME\s+\w+\s+TO\s+(\w+)|DROP\s+COLUMN\s+(\w+))', re.IGNORECASE)

            # Find all matches in the input string
                matches = alter_pattern.findall(sql_string)

                    # Extract table and operation details from matches
                        operations = []
                            for table, add, _, modify, rename, drop in matches:
                                    if add:
                                                columns = re.findall(r'(\w+)\s+\w+\([^)]+\)', add)
                                                            operations.extend([(table, 'ADD', column) for column in columns])
                                                                    elif modify:
                                                                                columns = re.findall(r'MODIFY\s+(\w+\s+\w+\([^)]+\))', sql_string)
                                                                                            operations.extend([(table, 'MODIFY', column) for column in columns])
                                                                                                    elif rename:
                                                                                                                operations.append((table, 'RENAME', rename))
                                                                                                                        elif drop:
                                                                                                                                    operations.append((table, 'DROP', drop))

                                                                                                                                        return operations

                                                                                                                                        # Example usage
                                                                                                                                        sql_query = "ALTER TABLE customers ADD COLUMN id INT, MODIFY COLUMN name VARCHAR(255), RENAME TO clients, DROP COLUMN product_name;"
                                                                                                                                        result = extract_alter_operations(sql_query)
                                                                                                                                        print(result)
                                                                                                                                        