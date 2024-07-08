# Build a scrollable list
- data class
- card
- LazyColumn
- items() in LazyListScope
``` kotlin
class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            AffirmationsTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    AffirmationsApp()
                }
            }
        }
    }
}



@Composable
@Preview
fun AffirmationsApp(modifier: Modifier = Modifier) {
    val layoutDirection = LocalLayoutDirection.current
    val sources = Datasource().loadAffirmations()
    Surface(
        modifier = modifier
            .fillMaxSize()
            .statusBarsPadding()
            .padding(
                start = WindowInsets.safeDrawing
                    .asPaddingValues()
                    .calculateStartPadding(layoutDirection),
                end = WindowInsets.safeDrawing
                    .asPaddingValues()
                    .calculateEndPadding(layoutDirection),
            ),
    ) {
        AffirmationList(list = sources)
    }

}

@Composable
fun AffirmationList(list: List<Affirmation>, modifier: Modifier = Modifier) {
    LazyColumn(modifier) {
        items(items=list) { item->
            Log.w("", "load: $item")
            AffirmationCard(affirmation = item, Modifier.padding(8.dp))
        }
    }
}

@Composable
fun AffirmationCard(affirmation: Affirmation, modifier: Modifier = Modifier) {
    Card(modifier) {
        Column {
            Image(
                painter = painterResource(id = affirmation.imageResourceId),
                contentDescription = null,
                contentScale = ContentScale.Crop,
                modifier = Modifier
                    .height(194.dp)
                    .fillMaxWidth()
            )
            Text(
                text = stringResource(id = affirmation.stringResourceId),
                style = MaterialTheme.typography.headlineSmall,
                modifier = Modifier.padding(16.dp)
            )
        }
    }
}
```
## Change the app icon
- launcher icon
- adaptive icons 
- Image Asset Studio
- screen density
- mipmap folder
- density qualifier
- Note that device screen densities won't be precisely 160 dpi, 240 dpi, 320 dpi, etc. Based on the device's screen density, Android selects the resource at the closest larger density bucket and then scales it down.
- adaptive icon - foreground, background, mask
- mipmap-anydpi-v26
- bitmap vs vector: The advantage is that a vector graphic can be scaled for any canvas size, for any screen density, without losing quality.
- 참고: https://developer.android.com/reference/kotlin/android/graphics/drawable/AdaptiveIconDrawable
- safe zone
- backwards compatibility
- legacy launcher icons
- Image Asset Studio
- 
## Build a grid
- Arrangement.spacedBy()
- LazyVerticalGrid
``` kotlin
class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            App()
        }
    }
}

@Composable
@Preview(showSystemUi = true)
fun App(modifier: Modifier = Modifier) {
    BuildAGridTheme {
        Surface(
            modifier
                .fillMaxSize()
                .statusBarsPadding()
        ) {
            TopicColumn(
                topics = DataSource.topics,
                Modifier.padding(8.dp)
            )
        }
    }
}

@Composable
fun TopicColumn(topics: List<Topic>, modifier: Modifier = Modifier) {
    LazyVerticalGrid(
        columns = GridCells.Fixed(2),
        verticalArrangement = Arrangement.spacedBy(8.dp),
        horizontalArrangement = Arrangement.spacedBy(8.dp),
        modifier = modifier
    ) {
        items(items= topics) {
            TopicCard(
                topic = it
            )
        }
    }

}

@Composable
fun TopicCard(topic: Topic, modifier: Modifier = Modifier) {
    Card(
        modifier
    ) {
        Row(
            modifier = Modifier
        ) {
            Image(
                painter = painterResource(id = topic.image),
                contentDescription = null,
                contentScale = ContentScale.Crop,
                modifier = Modifier.size(68.dp)
            )
            Column(
                verticalArrangement = Arrangement.spacedBy(8.dp),
                modifier = Modifier.padding(start=16.dp, top=16.dp, end=16.dp)
            ) {
                Text(
                    text = stringResource(id = topic.name),
                    style = MaterialTheme.typography.bodyMedium,
                    modifier = Modifier.fillMaxWidth()
                )
                Row(
                    verticalAlignment = Alignment.CenterVertically
                ) {
                    Icon(painter = painterResource(id = R.drawable.ic_grain), contentDescription = null)
                    Text(text = topic.cources.toString(), Modifier.padding(start=9.dp), style = MaterialTheme.typography.labelMedium)
                }
            }
        }
    }

}
```
