## Résultats bruts

| Implémentation | Temps réel (s) | Temps user (s) | Temps sys (s) |
| -------------- | -------------- | -------------- | ------------- |
| Linked List    | 10.232         | 8.680          | 1.465         |
| Dynamique      | 3.608          | 3.096          | 0.477         |
| Vector (STL)   | 4.637          | 4.087          | 0.500         |

## Analyse

-   **Tableau dynamique** est le plus rapide (≈ 3.6s).
-   **Vector (STL)** est légèrement plus lent (≈ 4.6s), mais reste proche.
-   **Liste chaînée** est beaucoup plus lente (≈ 10.2s) à cause de l’allocation dynamique de nœuds et de la faible localité mémoire.
