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
# Build beautiful apps
## Material Theming with Jetpack Compose
- color palette
- Typography
- Theme file
- color scheme
- hex color code, alpha
### Use Material Theme Builder to create a color scheme
- https://material-foundation.github.io/material-theme-builder/
---
- card
- dimens file
- Force Dark
- accessibility contrast standards(https://webaim.org/resources/contrastchecker/)
- Dynamic Color
- shape
- RoundedCornerShape
- Shape.kt file
- shape categories(https://m3.material.io/styles/shape/shape-scale-tokens#b09934f1-1b0f-4ce4-ade6-4a1f138add6c)
    - ![image](https://github.com/x1111101101/TIL/assets/97117787/6f41c5aa-fac8-4f3f-87ef-c88958edc6ee)
- Image Compose - ContentScale - Crop Modifier
- The Material Design type scale
- type scale - grouping: display, headline, title, body, label
- applying custom fonts
- Scaffold
- TopAppBar
- Window Insets
``` kotlin

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            WoofTheme {
                Surface(
                    modifier = Modifier.fillMaxSize()
                ) {
                    WoofApp()
                }
            }
        }
    }
}

/**
 * Composable that displays an app bar and a list of dogs.
 */
@Composable
fun WoofApp() {
    Scaffold(
        topBar = { WoofTopAppBar() }
    ) {
        LazyColumn(contentPadding = it) {
            items(dogs) {
                DogItem(
                    dog = it,
                    modifier=Modifier.padding(dimensionResource(id = R.dimen.padding_small))
                )
            }
        }
    }

}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun WoofTopAppBar(modifier: Modifier = Modifier) {
    CenterAlignedTopAppBar(
        title = {
            Row(
                verticalAlignment = Alignment.CenterVertically
            ) {
                Image(
                    modifier = Modifier
                        .size(dimensionResource(id = R.dimen.image_size))
                        .padding(dimensionResource(id = R.dimen.padding_small)),
                    painter = painterResource(R.drawable.ic_woof_logo),
                    contentDescription = null
                )
                Text(
                    text = stringResource(R.string.app_name),
                    style = MaterialTheme.typography.displayLarge
                )
            }
        },
        modifier = modifier
    )
}

/**
 * Composable that displays a list item containing a dog icon and their information.
 *
 * @param dog contains the data that populates the list item
 * @param modifier modifiers to set to this composable
 */
@Composable
fun DogItem(
    dog: Dog,
    modifier: Modifier = Modifier
) {
    Card(modifier) {
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .padding(dimensionResource(R.dimen.padding_small))
        ) {
            DogIcon(dog.imageResourceId)
            DogInformation(dog.name, dog.age)
        }
    }
}

/**
 * Composable that displays a photo of a dog.
 *
 * @param dogIcon is the resource ID for the image of the dog
 * @param modifier modifiers to set to this composable
 */
@Composable
fun DogIcon(
    @DrawableRes dogIcon: Int,
    modifier: Modifier = Modifier
) {
    Image(
        modifier = modifier
            .size(dimensionResource(R.dimen.image_size))
            .padding(dimensionResource(R.dimen.padding_small))
            .clip(MaterialTheme.shapes.small),
        painter = painterResource(dogIcon),
        contentScale = ContentScale.Crop,
        contentDescription = null
    )
}

/**
 * Composable that displays a dog's name and age.
 *
 * @param dogName is the resource ID for the string of the dog's name
 * @param dogAge is the Int that represents the dog's age
 * @param modifier modifiers to set to this composable
 */
@Composable
fun DogInformation(
    @StringRes dogName: Int,
    dogAge: Int,
    modifier: Modifier = Modifier
) {
    Column(modifier = modifier) {
        Text(
            text = stringResource(dogName),
            modifier = Modifier.padding(top = dimensionResource(R.dimen.padding_small)),
            style = MaterialTheme.typography.displayMedium
        )
        Text(
            text = stringResource(R.string.years_old, dogAge),
            style = MaterialTheme.typography.bodyLarge
        )
    }
}

/**
 * Composable that displays what the UI of the app looks like in light theme in the design tab.
 */
@Preview(showSystemUi = true)
@Composable
fun WoofPreview() {
    WoofTheme(darkTheme = false) {
        WoofApp()
    }
}
@Preview
@Composable
fun WoofDarkThemePreview() {
    WoofTheme(darkTheme = true) {
        WoofApp()
    }
}
```
![image](https://github.com/x1111101101/TIL/assets/97117787/c1c3d864-7148-43f0-be1e-3af7ab345149)

## Simple Animation with Jetpack Compose
### Add 'Expand more' Icon
- Material Design provides a number of icons, arranged in common categories, for most of your needs.
- Modifier.weight()
    - If the children don't have assigned weights, (weight is an optional parameter), then the child composable's height/width would default to wrap content (wrapping the contents of what's inside the UI element).
- Android Studio Preview - interactive mode
### Add Animation
- Animations can add visual cues that notify users about what's going on in your app.
- Spring Animation
    - Damping ratio
    - Stiffness level
- animate*AsState: similar to css transition
```
/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.woof

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.annotation.DrawableRes
import androidx.annotation.StringRes
import androidx.compose.animation.animateColorAsState
import androidx.compose.animation.animateContentSize
import androidx.compose.animation.core.Spring
import androidx.compose.animation.core.spring
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ExpandLess
import androidx.compose.material.icons.filled.ExpandMore
import androidx.compose.material3.Card
import androidx.compose.material3.CenterAlignedTopAppBar
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.dimensionResource
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.tooling.preview.Preview
import com.example.woof.data.Dog
import com.example.woof.data.dogs
import com.example.woof.ui.theme.WoofTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            WoofTheme {
                Surface(
                    modifier = Modifier.fillMaxSize()
                ) {
                    WoofApp()
                }
            }
        }
    }
}

/**
 * Composable that displays an app bar and a list of dogs.
 */
@Composable
fun WoofApp() {
    Scaffold(
        topBar = { WoofTopAppBar() }
    ) {
        LazyColumn(contentPadding = it) {
            items(dogs) {
                DogItem(
                    dog = it,
                    modifier=Modifier.padding(dimensionResource(id = R.dimen.padding_small))
                )
            }
        }
    }

}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun WoofTopAppBar(modifier: Modifier = Modifier) {
    CenterAlignedTopAppBar(
        title = {
            Row(
                verticalAlignment = Alignment.CenterVertically
            ) {
                Image(
                    modifier = Modifier
                        .size(dimensionResource(id = R.dimen.image_size))
                        .padding(dimensionResource(id = R.dimen.padding_small)),
                    painter = painterResource(R.drawable.ic_woof_logo),
                    contentDescription = null
                )
                Text(
                    text = stringResource(R.string.app_name),
                    style = MaterialTheme.typography.displayLarge
                )
            }
        },
        modifier = modifier
    )
}

/**
 * Composable that displays a list item containing a dog icon and their information.
 *
 * @param dog contains the data that populates the list item
 * @param modifier modifiers to set to this composable
 */
@Composable
fun DogItem(
    dog: Dog,
    modifier: Modifier = Modifier
) {
    var expanded by remember { mutableStateOf(false) }
    val color by animateColorAsState(
        targetValue = if (expanded) MaterialTheme.colorScheme.tertiaryContainer
        else MaterialTheme.colorScheme.secondaryContainer,
    )
    Card(modifier) {
        Column(
            Modifier
                .animateContentSize(spring(
                    dampingRatio = Spring.DampingRatioNoBouncy,
                    stiffness = Spring.StiffnessMedium
                ))
                .background(color)
        ) {
            Row(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(dimensionResource(R.dimen.padding_small))
            ) {
                DogIcon(dog.imageResourceId)
                DogInformation(dog.name, dog.age)
                Spacer(modifier = Modifier.weight(1f))
                DogItemButton(
                    expanded = expanded,
                    onClick = { expanded = !expanded }
                )
            }
            if(expanded) {
                DogHobby(
                    dogHobby = dog.hobbies,
                    modifier = Modifier
                        .padding(
                            start = dimensionResource(R.dimen.padding_medium),
                            top = dimensionResource(R.dimen.padding_small),
                            end = dimensionResource(R.dimen.padding_medium),
                            bottom = dimensionResource(R.dimen.padding_medium)
                        )
                )
            }
        }

    }
}

@Composable
fun DogHobby(
    @StringRes dogHobby: Int,
    modifier: Modifier = Modifier
) {
    Column(
        modifier = modifier
    ) {
        Text(
            text = stringResource(R.string.about),
            style = MaterialTheme.typography.labelSmall
        )
        Text(
            text = stringResource(dogHobby),
            style = MaterialTheme.typography.bodyLarge
        )
    }
}

/**
 * Composable that displays a photo of a dog.
 *
 * @param dogIcon is the resource ID for the image of the dog
 * @param modifier modifiers to set to this composable
 */
@Composable
fun DogIcon(
    @DrawableRes dogIcon: Int,
    modifier: Modifier = Modifier
) {
    Image(
        modifier = modifier
            .size(dimensionResource(R.dimen.image_size))
            .padding(dimensionResource(R.dimen.padding_small))
            .clip(MaterialTheme.shapes.small),
        painter = painterResource(dogIcon),
        contentScale = ContentScale.Crop,
        contentDescription = null
    )
}

/**
 * Composable that displays a dog's name and age.
 *
 * @param dogName is the resource ID for the string of the dog's name
 * @param dogAge is the Int that represents the dog's age
 * @param modifier modifiers to set to this composable
 */
@Composable
fun DogInformation(
    @StringRes dogName: Int,
    dogAge: Int,
    modifier: Modifier = Modifier
) {
    Column(modifier = modifier) {
        Text(
            text = stringResource(dogName),
            modifier = Modifier.padding(top = dimensionResource(R.dimen.padding_small)),
            style = MaterialTheme.typography.displayMedium
        )
        Text(
            text = stringResource(R.string.years_old, dogAge),
            style = MaterialTheme.typography.bodyLarge
        )
    }
}

@Composable
private fun DogItemButton(
    expanded: Boolean,
    onClick: () -> Unit,
    modifier: Modifier = Modifier
) {
    val imgVector = if(expanded) Icons.Filled.ExpandLess else Icons.Filled.ExpandMore
    IconButton(
        onClick = onClick,
        modifier = modifier
    ) {
        Icon(
            imageVector = imgVector,
            contentDescription = stringResource(R.string.expand_button_content_description),
            tint = MaterialTheme.colorScheme.secondary
        )
    }
}

/**
 * Composable that displays what the UI of the app looks like in light theme in the design tab.
 */
@Preview(showSystemUi = true)
@Composable
fun WoofPreview() {
    WoofTheme(darkTheme = false) {
        WoofApp()
    }
}
@Preview
@Composable
fun WoofDarkThemePreview() {
    WoofTheme(darkTheme = true) {
        WoofApp()
    }
}
```
- 참고: https://www.youtube.com/watch?v=Z_T1bVjhMLk

